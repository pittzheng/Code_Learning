/*
* for learn class
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

static char *Version = "revision 1.0, scclass";

struct class test_class=
{
    .name = "test_class",     //将类的名字设置为test-cla
    .owner = THIS_MODULE,   //该类的拥有者为这个模块
};

EXPORT_SYMBOL_GPL(test_class);

/*
* export class attribute
*/
static ssize_t class_show_version(struct class *class, 
				struct class_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", Version);
}
CLASS_ATTR(version, S_IRUSR | S_IWUSR, class_show_version, NULL);

static int __init test_class_init(void)
{
	int err;

	err = class_register(&test_class);
	if (err)
		return err;

	err = class_create_file(&test_class, &class_attr_version);
	if (err)
		goto err_class_create;

	printk("%s\n", __func__);
	return 0;

err_class_create:
	class_unregister(&test_class);
	return err;
}

static void __exit test_class_exit(void)
{
	class_remove_file(&test_class, &class_attr_version);
	class_unregister(&test_class);
	printk("%s\n", __func__);
}

module_init(test_class_init);
module_exit(test_class_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CJOK <cjok.liao@gmail.com>");
