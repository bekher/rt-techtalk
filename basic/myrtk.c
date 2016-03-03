#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/unistd.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name here");

unsigned long *syscall_table = (unsigned long *) 0x//Address here!;

asmlinkage long (*original_write)(unsigned int, const char __user *, size_t);

asmlinkage long new_write(unsigned int fd, const char __user *buf, size_t count) {
    // hijacked write
    
    // YOUR CODE HERE!
    // what should we return? 
}

static int init(void) {

    printk(KERN_ALERT "Entering the kernel");

 	// disable write protection, flip bit 16
    write_cr0 (read_cr0 () & (~ 0x10000));
    
    // YOUR CODE HERE!
    // hint: you do the hook here

 	// enable write protection, flip bit 16
    write_cr0 (read_cr0 () | 0x10000);

    return 0;
}

static void exit(void) {

    write_cr0 (read_cr0 () & (~ 0x10000));

   // YOUR CODE HERE!
   // hint: you unhook here

    write_cr0 (read_cr0 () | 0x10000);

    printk(KERN_ALERT "MODULE EXIT\n");

}

module_init(init);
module_exit(exit);
