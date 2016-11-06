#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/debugfs.h>
#include <linux/seq_file.h>
#include <linux/fs.h>
#include <linux/stat.h>

#define DEBUGFS 1
void foo_debug_dump_version(struct seq_file *s)
{
    int tmp=1.0;
    seq_printf(s, "==============\n %s \n", "foo_debug_dump_version");
    seq_printf(s,"version: %d \n",tmp);
   
}

static int foo_debugfs_show(struct seq_file *s, void *data)
{
    printk("%s \n", __func__);
    void (*func)(struct seq_file *) = s->private;
    func(s);
    //seq_printf(s,"version: %s \n","1.0");
    return 0;
}

static int foo_debugfs_open(struct inode *inode, struct file *file)
{
    printk("%s \n", __func__);
    return single_open(file, foo_debugfs_show, inode->i_private);
}


static const struct file_operations foo_debugfs_fops = {
    .open = foo_debugfs_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

//step 1
struct dentry *foo_debugfs_dir;

static int foo_probe(void)
{
    printk("%s", __func__);
//debugfs
    foo_debugfs_dir = debugfs_create_dir("foo_debug",NULL);
    if (IS_ERR(foo_debugfs_dir)) {
        goto err_node;
    }

    debugfs_create_file("foo_version", ( S_IRUGO | S_IWUSR ), foo_debugfs_dir,
                &foo_debug_dump_version, &foo_debugfs_fops);
    pr_info(" debugfs entries created ");
    return 0;
//~debugfs  
err_node:
    debugfs_remove_recursive(foo_debugfs_dir);
    foo_debugfs_dir = NULL;
    pr_err(" debugfs entries creation failed ");
    return -EIO;

}

static int __init foo_init(void)
{
    printk("foo init\n");
    return foo_probe();
}

static void __exit foo_exit(void)
{
    printk("foo exit\n");
    debugfs_remove_recursive(foo_debugfs_dir);
    foo_debugfs_dir = NULL;
    return ;
}

module_init(foo_init);
module_exit(foo_exit);

MODULE_AUTHOR("Late Lee");
MODULE_DESCRIPTION("foo driver ");
MODULE_LICENSE("GPL");
