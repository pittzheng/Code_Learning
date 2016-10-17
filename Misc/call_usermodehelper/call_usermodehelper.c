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

#include <linux/kmod.h>

static int __init foo_drv_init(void)
{
    int err;
    char * envp[] = { "HOME=/", NULL };
    char * argv[] = { "/bin/mkdir", "-p","/home/peiqzhen/rocky/peiqzhen123", NULL };

    err = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);

    if(err < 0 )
    {
        printk("call_usermodehelper failed\n");
        return -1;
    }
    else
    {
        return 0;
    }

}

static void __exit foo_drv_exit(void)
{
    printk("exit OK!\n");
}

module_init(foo_drv_init);
module_exit(foo_drv_exit);

MODULE_AUTHOR("Late Lee");
MODULE_DESCRIPTION("Simple platform driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:foo");
