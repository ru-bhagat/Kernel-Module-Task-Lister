# Kernel-Module-For-Task-Lister
The OS Task Lister is a kernel module designed to provide detailed information about the tasks running on a Linux operating system. By integrating directly with the kernel, this module offers a powerful and efficient way to monitor and manage system processes.

## Steps for Execution
```
1. $ cd /home/yoursysname/OS-Task-Lister-using-Kernel-Module/dir1
2. $ make
3. $ sudo insmod tasks_lister_dfs.ko
4. $ sudo dmesg
5. $ sudo rmmod tasks_lister_dfs
6. $ sudo dmesg
7. $ dmesg -C
```

## Example of Output
```
[ 2539.819551] pid: 2115 | pname: kworker/1:2 | state: I ]
This indicates:
pid: The process ID.
pname: The process name.
state: The state of the process, converted to a human-readable form. The state I typically represents "idle".
```
## Expected Output 
```
![output](https://github.com/ru-bhagat/Kernel-Module-Task-Lister/assets/167604594/6d4f0a5c-7ece-48c5-aaad-ff48f82af4dd)

```
