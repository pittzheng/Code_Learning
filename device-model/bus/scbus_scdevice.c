/*
* for learn bus
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type scbus_type;

static void scbus_scdevice_release(struct device *dev)
{
	printk("%s\n", __func__);
}

struct device scdevice = {
	.init_name	= "scdevice",
	.release	= scbus_scdevice_release,
    .bus       = &scbus_type,
};


static int __init scbus_scdevice_init(void)
{
	int ret;

	ret = device_register(&scdevice);
	if (ret)
	    return -1;

	printk("%s\n", __func__);
	return 0;
}

static void __exit scbus_scdevice_exit(void)
{
	device_unregister(&scdevice);
	printk("%s\n", __func__);
}

module_init(scbus_scdevice_init);
module_exit(scbus_scdevice_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
MODULE_DESCRIPTION("A bus");
