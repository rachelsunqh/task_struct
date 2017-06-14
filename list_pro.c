#include <linux/errno.h>
#include <linux/init_task.h>

#include <linux/module.h>
#include <linux/kernel.h>

int __init lps_init(void)
{
    struct task_struct *task,*p;  
    struct list_head *pos;  
    int count=0;  
    printk("Hello,let begin\n");  
    task=&init_task;  
    list_for_each(pos,&task->tasks){  
        p=list_entry(pos,struct task_struct,tasks);  
        count++;  
        printk("stack:0x%x %d---->%s\n",p->stack,p->pid,p->comm);  
    }  
    printk("the number of process is:%d\n",count);  
    return 0; 

}


void __exit lps_exit(void)
{


	return;

}

module_init(lps_init);
module_exit(lps_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sqhxhg@sbs.com.cn");
MODULE_DESCRIPTION("watch the task struct");
