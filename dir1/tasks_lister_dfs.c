#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rutuja");
MODULE_DESCRIPTION("A simple Linux kernel module to list processes in a tree structure");
MODULE_VERSION("1.0");

void dfs(struct task_struct *task);
int tasks_lister_dfs_init(void);
void tasks_lister_dfs_exit(void);

void dfs(struct task_struct *task) {
    struct task_struct *task_next;
    struct list_head *list;
    char state;

    state = task_state_to_char(task);
    printk(KERN_INFO "pid: %d | pname: %s | state: %c\n", task->pid, task->comm, state);

    list_for_each(list, &task->children) {
        task_next = list_entry(list, struct task_struct, sibling);
        dfs(task_next);
    }
}

int tasks_lister_dfs_init(void) {
    struct task_struct *task = &init_task;
    printk(KERN_INFO "Loading tasks_lister_dfs module...\n");
    dfs(task);
    return 0;
}

void tasks_lister_dfs_exit(void) {
    printk(KERN_INFO "Unloading tasks_lister_dfs module...\n");
}

module_init(tasks_lister_dfs_init);
module_exit(tasks_lister_dfs_exit);
