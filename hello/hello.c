/*  
 *  hello.c
 */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */
#include <linux/init.h> /* Needed for the macros */

MODULE_LICENSE("GPL");      /* Prevent “tainting” the kernel */
MODULE_AUTHOR("Your Name Here");

// Your code here

module_init(...);
module_exit(...);

