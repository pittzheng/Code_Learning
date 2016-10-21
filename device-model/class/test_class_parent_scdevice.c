/*
* for learn bus
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct class test_class;

static void test_class_parent_scdevice_release(struct device *dev)
{
	printk("%s\n", __func__);
}

static void scdevice_parent_release(struct device *dev)
{
	printk("%s\n", __func__);
}

struct device scdevice_parent = {
	.init_name	= "scdevice_parent",
	.release	= scdevice_parent_release,
};

struct device scdevice = {
    .parent     = &scdevice_parent,
	.init_name	= "scdevice",
	.release	= test_class_parent_scdevice_release,
    .class      = &test_class,
};


static int __init test_class_parent_scdevice_init(void)
{
	int ret;

    ret = device_register(&scdevice_parent);
    if (ret)
        return -1;
	ret = device_register(&scdevice);
	if (ret)
        goto exit;

	printk("%s\n", __func__);
	return 0;
exit:
	device_unregister(&scdevice_parent);
    return ret;
}

static void __exit test_class_parent_scdevice_exit(void)
{
	device_unregister(&scdevice_parent);
	device_unregister(&scdevice);
	printk("%s\n", __func__);
}

module_init(test_class_parent_scdevice_init);
module_exit(test_class_parent_scdevice_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
MODULE_DESCRIPTION("A bus");
