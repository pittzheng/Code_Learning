/*
* for learn device
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/slab.h>

/*extern struct bus_type scbus_type;*/
/*extern struct device scbus;*/

struct device *u_device = NULL;
static int firmware_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	if (add_uevent_var(env, "FIRMWARE=%s", "uevent_example"))
		return -ENOMEM;
	if (add_uevent_var(env, "TIMEOUT=%i", 60))
		return -ENOMEM;
	return 0;
}

static struct class scclass =
{
    .name = "scclass",
    .dev_uevent =firmware_uevent,
};

static char *Version = "revision 1.0, scdevice";

void screlease(struct device *dev)
{
	printk("scbus release\n");
}

struct device scdevice = {
/*    .parent	= &scbus,*/
	.init_name	= "scdevice0",
/*    .bus	= &scbus_type,*/
	.release	= screlease,
	.devt = ((250 << 20) | 3),	//define devno, create device node file
								//under /dev/
};

static ssize_t store_device_version(struct device *dev, 
			struct device_attribute *attr, const char *buf, size_t size)
{
    unsigned long state = simple_strtoul(buf, NULL, 10);
    int ret;
    printk("got data from user space: %d\n", (unsigned int)state);

    if(!u_device)
    {
        u_device = kzalloc(sizeof(*u_device), GFP_KERNEL);

        if(!u_device)
        {
            printk("kzalloc failed\n");
            goto exit;
        }

        device_initialize(u_device);
        dev_set_name(u_device, "%s", "uevent_example_dev");
        u_device->parent = dev;
        u_device->class = &scclass;

        ret = device_add(u_device);
        if (ret)
        {
            printk("device_add failed\n");
            kfree(u_device);
            u_device = NULL;
            goto exit;
        }
    }
exit:
    return size;
}

/*
* export device attribute
*/
static ssize_t show_device_version(struct device *dev, 
			struct device_attribute *attr, char *buf)
{
    if(u_device)
    {
        kfree(u_device);
        u_device = NULL;
    }

	return sprintf(buf, "%s\n", Version);
}
DEVICE_ATTR(version, S_IRUSR | S_IWUSR, show_device_version, store_device_version);


static int __init scdevice_init(void)
{
	int ret;

	ret = class_register(&scclass);
    if(ret)
        return ret;

	ret = device_register(&scdevice);
	if (ret) 
		return ret;

	ret = device_create_file(&scdevice, &dev_attr_version);
	if (ret)
		goto err_create;
	
	printk("Create a scdevice");
	return 0;

err_create:
	device_unregister(&scdevice);
	return ret;
}

static void __exit scdevice_exit(void)
{
	device_remove_file(&scdevice, &dev_attr_version);
	device_unregister(&scdevice);
	class_unregister(&scclass);
	printk("Remove a scdevice");
}

module_init(scdevice_init);
module_exit(scdevice_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
