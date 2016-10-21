/*
* for learn bus
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

static void scdevice_release(struct device *dev)
{
	printk("scdevice release\n");
}

struct device scdevice = {
	.init_name	= "scdevice",
	.release	= scdevice_release,
};


static int __init scdevice_init(void)
{
	int ret;

	ret = device_register(&scdevice);
	if (ret)
	    return -1;

	printk("%s\n", __func__);
	return 0;
}

static void __exit scdevice_exit(void)
{
	device_unregister(&scdevice);
	printk("%s\n", __func__);
}

module_init(scdevice_init);
module_exit(scdevice_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
MODULE_DESCRIPTION("A bus");
