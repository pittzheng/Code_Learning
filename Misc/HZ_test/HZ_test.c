/*
 *    Filename: cfag12864b.c
 *     Version: 0.1.0
 * Description: cfag12864b LCD driver
 *     License: GPLv2
 *     Depends: ks0108
 *
 *      Author: Copyright (C) Miguel Ojeda Sandonis
 *        Date: 2006-10-31
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/workqueue.h>
#include <linux/ks0108.h>
#include <linux/cfag12864b.h>


#define CFAG12864B_NAME "cfag12864b"

/*
 * Module Parameters
 */

static unsigned int cfag12864b_rate = 20;
module_param(cfag12864b_rate, uint, S_IRUGO);
MODULE_PARM_DESC(cfag12864b_rate,
	"Refresh rate (hertz)");
/*
 * Update work
 */

static DEFINE_MUTEX(cfag12864b_mutex);
static unsigned char cfag12864b_updating;
static void cfag12864b_update(struct work_struct *delayed_work);
static struct workqueue_struct *cfag12864b_workqueue;
static DECLARE_DELAYED_WORK(cfag12864b_work, cfag12864b_update);

static void cfag12864b_queue(void)
{
	queue_delayed_work(cfag12864b_workqueue, &cfag12864b_work,
		HZ / cfag12864b_rate);
}

unsigned char cfag12864b_enable(void)
{
	unsigned char ret;

	mutex_lock(&cfag12864b_mutex);

	if (!cfag12864b_updating) {
		cfag12864b_updating = 1;
		cfag12864b_queue();
		ret = 0;
	} else
		ret = 1;

	mutex_unlock(&cfag12864b_mutex);

	return ret;
}

void cfag12864b_disable(void)
{
	mutex_lock(&cfag12864b_mutex);

	if (cfag12864b_updating) {
		cfag12864b_updating = 0;
		cancel_delayed_work(&cfag12864b_work);
		flush_workqueue(cfag12864b_workqueue);
	}

	mutex_unlock(&cfag12864b_mutex);
}

unsigned char cfag12864b_isenabled(void)
{
	return cfag12864b_updating;
}

static void cfag12864b_update(struct work_struct *work)
{
    struct timeval now;
    long long milliseconds;
    do_gettimeofday(&now);
    milliseconds = now.tv_sec*1000LL + now.tv_usec/1000;
    printk("%lld ms\n", milliseconds);

	if (cfag12864b_updating)
		cfag12864b_queue();
}

static int __init cfag12864b_init(void)
{
	int ret = -EINVAL;

	cfag12864b_workqueue = create_singlethread_workqueue(CFAG12864B_NAME);
	if (cfag12864b_workqueue == NULL)
		goto none;
    cfag12864b_enable();

	return 0;

none:
	return ret;
}

static void __exit cfag12864b_exit(void)
{
	cfag12864b_disable();
	destroy_workqueue(cfag12864b_workqueue);
}

module_init(cfag12864b_init);
module_exit(cfag12864b_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Miguel Ojeda Sandonis <miguel.ojeda.sandonis@gmail.com>");
MODULE_DESCRIPTION("cfag12864b LCD driver");
