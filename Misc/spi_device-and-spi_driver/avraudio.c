#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/spi/spi.h>
#include <linux/string.h>
#include <asm/uaccess.h>

#define PFX "avraudio: "
#define SPI_BUFF_SIZE 16
#define USER_BUFF_SIZE 128

const char this_driver_name[] = "avraudio";

struct avraudio_dev {
 struct semaphore spi_sem;
 struct semaphore fop_sem;
 dev_t devt;
 struct cdev cdev;
 struct class *class;
 struct spi_device *spi_device;
 char *user_buff;
 u8 test_data; 
};

static struct avraudio_dev avraudio_dev;

static int avraudio_probe(struct spi_device *spi_device)
{
 printk(KERN_INFO PFX "probe.\n");

 if (down_interruptible(&avraudio_dev.spi_sem))
 return -EBUSY;

 avraudio_dev.spi_device = spi_device;

 up(&avraudio_dev.spi_sem);

 return 0;
}


static int __devexit avraudio_remove(struct spi_device *spi)
{
 printk(KERN_INFO PFX "remove.\n");

 if (down_interruptible(&avraudio_dev.spi_sem))
 return -EBUSY;

 avraudio_dev.spi_device = NULL;

 up(&avraudio_dev.spi_sem);

 return 0;

}

struct avraudio_control {
 struct spi_message msg;
 struct spi_transfer transfer;
 u8 *tx_buff; 
 u8 *rx_buff;
};

static struct avraudio_control avraudio_ctl;

static void avraudio_prepare_spi_message(void)
{
 spi_message_init(&avraudio_ctl.msg);

 /* put some changing values in tx_buff for testing */ 
 avraudio_ctl.tx_buff[0] = avraudio_dev.test_data++;
 avraudio_ctl.tx_buff[1] = avraudio_dev.test_data++;
 avraudio_ctl.tx_buff[2] = avraudio_dev.test_data++;
 avraudio_ctl.tx_buff[3] = avraudio_dev.test_data++;

 memset(avraudio_ctl.rx_buff, 0, SPI_BUFF_SIZE);

 avraudio_ctl.transfer.tx_buf = avraudio_ctl.tx_buff;
 avraudio_ctl.transfer.rx_buf = avraudio_ctl.rx_buff;
 avraudio_ctl.transfer.len = 4;

 spi_message_add_tail(&avraudio_ctl.transfer, &avraudio_ctl.msg);
}

static int avraudio_do_one_message(void)
{
 int status;

 if (down_interruptible(&avraudio_dev.spi_sem))
 return -ERESTARTSYS;

 if (!avraudio_dev.spi_device) {
 up(&avraudio_dev.spi_sem);
 return -ENODEV;
 }

 avraudio_prepare_spi_message();

 status = spi_sync(avraudio_dev.spi_device, &avraudio_ctl.msg);

 up(&avraudio_dev.spi_sem);

 return status; 
}


static ssize_t avraudio_read(struct file *filp, char __user *buff, size_t count,
 loff_t *offp)
{
 size_t len;
 ssize_t status = 0;
 printk(KERN_INFO PFX "read.\n");

 if (!buff) 
 return -EFAULT;

 if (*offp > 0) 
 return 0;

 if (down_interruptible(&avraudio_dev.fop_sem)) 
 return -ERESTARTSYS;

 status = avraudio_do_one_message();

 if (status) {
 sprintf(avraudio_dev.user_buff, 
 "avraudio_do_one_message failed : %d\n",
 status);
 }
 else {
 sprintf(avraudio_dev.user_buff, 
 "Status: %d\nTX: %d %d %d %d\nRX: %d %d %d %d\n",
 avraudio_ctl.msg.status,
 avraudio_ctl.tx_buff[0], avraudio_ctl.tx_buff[1], 
 avraudio_ctl.tx_buff[2], avraudio_ctl.tx_buff[3],
 avraudio_ctl.rx_buff[0], avraudio_ctl.rx_buff[1], 
 avraudio_ctl.rx_buff[2], avraudio_ctl.rx_buff[3]);
 }

 len = strlen(avraudio_dev.user_buff);

 if (len < count) 
 count = len;

 if (copy_to_user(buff, avraudio_dev.user_buff, count))  {
 printk(KERN_ALERT "avraudio_read(): copy_to_user() failed\n");
 status = -EFAULT;
 } else {
 *offp += count;
 status = count;
 }

 up(&avraudio_dev.fop_sem);

 return status;
}

static int avraudio_open(struct inode *inode, struct file *filp)
{ 
 int status = 0;
 printk(KERN_INFO PFX "open.\n");


 if (down_interruptible(&avraudio_dev.fop_sem)) 
 return -ERESTARTSYS;

 if (!avraudio_dev.user_buff) {
 avraudio_dev.user_buff = kmalloc(USER_BUFF_SIZE, GFP_KERNEL);
 if (!avraudio_dev.user_buff) 
 status = -ENOMEM;
 } 

 up(&avraudio_dev.fop_sem);

 return status;
}

static const struct file_operations avraudio_fops = {
 .owner = THIS_MODULE,
 .read =  avraudio_read,
 .open = avraudio_open, 
};

static struct spi_driver avraudio_driver = {
 .driver = {
 .name = "avraudio",
 .bus = &spi_bus_type,
 .owner = THIS_MODULE,
 },
 .probe = avraudio_probe,
 .remove = __devexit_p(avraudio_remove),
};



static int __init avraudio_modinit(void)
{
 int error;

 printk(KERN_INFO PFX "init.\n");

 memset(&avraudio_dev, 0, sizeof(avraudio_dev));

 sema_init(&avraudio_dev.spi_sem, 1);
 sema_init(&avraudio_dev.fop_sem, 1);

 /*
  * char device
  */

 avraudio_dev.devt = MKDEV(0, 0);

 error = alloc_chrdev_region(&avraudio_dev.devt, 0, 1, this_driver_name);
 if (error < 0) {
 printk(KERN_ALERT "alloc_chrdev_region() failed: %d \n", 
 error);
 return -1;
 }

 cdev_init(&avraudio_dev.cdev, &avraudio_fops);
 avraudio_dev.cdev.owner = THIS_MODULE;

 error = cdev_add(&avraudio_dev.cdev, avraudio_dev.devt, 1);
 if (error) {
 printk(KERN_ALERT "cdev_add() failed: %d\n", error);
 unregister_chrdev_region(avraudio_dev.devt, 1);
 return -1;
 } 
 printk(KERN_INFO PFX "char device created.\n");

 /*
  * class
  */

 avraudio_dev.class = class_create(THIS_MODULE, this_driver_name);

 if (!avraudio_dev.class) {
 printk(KERN_ALERT "class_create() failed\n");
 return -1;
 }

 if (!device_create(avraudio_dev.class, NULL, avraudio_dev.devt, NULL,  
 this_driver_name)) {
 printk(KERN_ALERT "device_create(..., %s) failed\n",
 this_driver_name);
 class_destroy(avraudio_dev.class);
 return -1;
 }

 printk(KERN_INFO PFX "class created.\n");

 /* 
  * spi device 
  */

 avraudio_ctl.tx_buff = kmalloc(SPI_BUFF_SIZE, GFP_KERNEL | GFP_DMA);
 if (!avraudio_ctl.tx_buff) {
 error = -ENOMEM;
 goto avraudio_init_error;
 }

 avraudio_ctl.rx_buff = kmalloc(SPI_BUFF_SIZE, GFP_KERNEL | GFP_DMA);
 if (!avraudio_ctl.rx_buff) {
 error = -ENOMEM;
 goto avraudio_init_error;
 }

 spi_register_driver(&avraudio_driver);

 printk(KERN_INFO PFX "spi driver registered.\n");


avraudio_init_error:

 return error;
}
module_init(avraudio_modinit);

static void __exit avraudio_modexit(void)
{
 printk(KERN_INFO PFX "exit.\n");

 spi_unregister_driver(&avraudio_driver);

 device_destroy(avraudio_dev.class, avraudio_dev.devt);
 class_destroy(avraudio_dev.class);

 cdev_del(&avraudio_dev.cdev);
 unregister_chrdev_region(avraudio_dev.devt, 1);

 if (avraudio_dev.user_buff)
 kfree(avraudio_dev.user_buff);

}
module_exit(avraudio_modexit);

MODULE_AUTHOR("Guenter Bartsch");
MODULE_DESCRIPTION("avraudio module - audio output via AVR PWM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");