/**
* @file   sysfs_drv.c
* @author Late Lee <latelee@163.com>
* @date   Tue Nov 12 22:21:19 2013
*
* @brief  sysfs测试示例
*
* @note
*/

#include <linux/module.h>
#include <linux/kernel.h>       /**< printk() */
#include <linux/init.h>
#include <linux/platform_device.h>

#include <linux/cdev.h>         /**< cdev_* */
#include <linux/fs.h>
#include <asm/uaccess.h>        /**< copy_*_user */

#include <linux/types.h>        /**< size_t */
#include <linux/errno.h>        /**< error codes */
#include <linux/string.h>
#include <linux/ctype.h>

static void foo_dev_release(struct device* dev)
{
    
}

// platform设备
static struct platform_device foo_device = {
    .name    = "foo",
    .id      = -1,
    .dev     = {
    //.platform_data = &foo_pdata,
    .release = &foo_dev_release,
    },
};

#define DEBUG

#ifdef DEBUG
/* KERN_INFO */
#define debug(fmt, ...) printk(KERN_NOTICE fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

static struct class* foo_class;
static int user_data = 250;

// cat foobar　调用此函数
static ssize_t foobar_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
    printk("set data to user space: %d\n", user_data);
    return sprintf(buf, "%u\n", user_data);
}

// echo 111 > foobar　调用此函数
static ssize_t foobar_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
    unsigned long state = simple_strtoul(buf, NULL, 10);
    user_data = state;
    printk("got data from user space: %d %d\n", (unsigned int)state, user_data);
    // 一定要返回size，否则会一直执行
    return size;
}

static struct device_attribute dev_attr_foobar = {
    .attr = {
        .name = "foobar",
        .mode = S_IRUSR | S_IWUSR
    },
    .show = foobar_show,
    .store = foobar_store
};

// 生成文件为foobar
/*static DEVICE_ATTR(foobar, 0666, foobar_show, foobar_store);*/

static int foo_remove(struct platform_device *dev)
{
    device_remove_file(&foo_device.dev, &dev_attr_foobar);

    class_destroy(foo_class);

    //printk(KERN_NOTICE "remove...\n");

    return 0;
}

static int foo_probe(struct platform_device *dev)
{
    int ret = 0;

    foo_class = class_create(THIS_MODULE, "foo");
    if (IS_ERR(foo_class))
    {
        dev_err(&foo_device.dev, "failed to create class.\n");
        return PTR_ERR(foo_class);
    }

    ret = device_create_file(&foo_device.dev, &dev_attr_foobar);
    if (ret)
    goto err_out;

    err_out:
    return ret;
}

// driver
static struct platform_driver foo_driver = {
    .probe        = foo_probe,
    .remove        = foo_remove,
    .driver        = {
    .name        = "foo",
    .owner        = THIS_MODULE,
    },
};

static int __init foo_drv_init(void)
{
    int ret = 0;

    // 先注册设备(适用于静态定义设备结构体)
    ret = platform_device_register(&foo_device);
    if (ret)
    {
        dev_err(&foo_device.dev, "platform_device_register failed!\n");
        return ret;
    }
    // 再注册驱动
    ret = platform_driver_register(&foo_driver);
    if (ret)
    {
        dev_err(&foo_device.dev, "platform_driver_register failed!\n");
        return ret;
    }
    dev_info(&foo_device.dev, "init OK!\n");
    return ret;
}

static void __exit foo_drv_exit(void)
{
    // 先卸载驱动
    platform_driver_unregister(&foo_driver);
    // 再卸载设备
    platform_device_unregister(&foo_device);

    printk("exit OK!\n");
}

module_init(foo_drv_init);
module_exit(foo_drv_exit);

MODULE_AUTHOR("Late Lee");
MODULE_DESCRIPTION("Simple platform driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:foo");
