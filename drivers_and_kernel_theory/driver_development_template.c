#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int __init my_init(void) {
    printk(KERN_INFO "Hello, Driver!\n");
    return 0;
}

static void __exit my_exit(void) {
    printk(KERN_INFO "Goodbye, Driver!\n");
}

module_init(my_init);
module_exit(my_exit);