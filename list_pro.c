#include <linux/errno.h>
#include <linux/init_task.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cred.h>
#if 0
struct cred {
        atomic_t        usage;
#ifdef CONFIG_DEBUG_CREDENTIALS
        atomic_t        subscribers;    /* number of processes subscribed */
        void            *put_addr;
        unsigned        magic;
#define CRED_MAGIC      0x43736564
#define CRED_MAGIC_DEAD 0x44656144
#endif
        kuid_t          uid;            /* real UID of the task */
        kgid_t          gid;            /* real GID of the task */
        kuid_t          suid;           /* saved UID of the task */
        kgid_t          sgid;           /* saved GID of the task */
        kuid_t          euid;           /* effective UID of the task */
        kgid_t          egid;           /* effective GID of the task */
        kuid_t          fsuid;          /* UID for VFS ops */
        kgid_t          fsgid;          /* GID for VFS ops */
        unsigned        securebits;     /* SUID-less security management */
        kernel_cap_t    cap_inheritable; /* caps our children can inherit */
        kernel_cap_t    cap_permitted;  /* caps we're permitted */
        kernel_cap_t    cap_effective;  /* caps we can actually use */
        kernel_cap_t    cap_bset;       /* capability bounding set */
        kernel_cap_t    cap_ambient;    /* Ambient capability set */
#ifdef CONFIG_KEYS
        unsigned char   jit_keyring;    /* default keyring to attach requested
                                         * keys to */
        struct key __rcu *session_keyring; /* keyring inherited over fork */
        struct key      *process_keyring; /* keyring private to this process */
        struct key      *thread_keyring; /* keyring private to this thread */
        struct key      *request_key_auth; /* assumed request_key authority */
#endif
#ifdef CONFIG_SECURITY
        void            *security;      /* subjective LSM security */
#endif
        struct user_struct *user;       /* real user ID subscription */
        struct user_namespace *user_ns; /* user_ns the caps and keyrings are relative to. */
        struct group_info *group_info;  /* supplementary groups for euid/fsgid */
        struct rcu_head rcu;            /* RCU deletion hook */
};

#endif

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
 	printk("\t uid =%d gid =%d \n",p->cred->uid,p->cred->gid); 

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
