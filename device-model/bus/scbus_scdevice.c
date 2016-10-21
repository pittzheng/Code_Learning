/*
* for learn bus
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type scbus_type;

static void scbus_release(struct device *dev)
{
	printk("scbus release\n");
}

struct device scdevice = {
	.init_name	= "scdevice",
	.release	= scbus_release,
    .bus       = &scbus_type,
};


static int __init scbus_init(void)
{
	int ret;

	ret = device_register(&scdevice);
	if (ret)
	    return -1;

	printk("Create a scbus\n");
	return 0;
}

static void __exit scbus_exit(void)
{
	device_unregister(&scdevice);
	printk("Remove a scbus\n");
}

module_init(scbus_init);
module_exit(scbus_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
MODULE_DESCRIPTION("A bus");
