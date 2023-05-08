// C program to illustrate use of fork() &
// exec() system call for process creation

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int ret = 1;
    int status;

    printf("Before fork. getpid()=%u, getppid()=%u\n", getpid(), getppid());
    pid = fork();
    printf("\nAfter fork...\n");
    if (pid == -1)
    {
        // pid == -1 means error occurred
        printf("can't fork, error occurred\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // pid == 0 means child process created
        // getpid() returns process id of calling process
        // Here It will return process id of child process
        printf("pid = fork() returned 0 (child process created)\n");
        printf("child process, pid = %u\n",getpid());
        // Here It will return Parent of child Process means Parent process it self
        printf("parent of child process, pid = %u\n",getppid());

        // the argv list first argument should point to
        // filename associated with file being executed
        // the array pointer must be terminated by NULL
        // pointer
        char* argv_list[] = {"ls","-lart","/home",NULL};

        // the execv() only return if error occurred.
        // The return value is -1
        execv("ls",argv_list);
        exit(0);
    }
    else
    {
        // a positive number is returned for the pid of
        // parent process
        // getppid() returns process id of parent of
        // calling process
        // Here It will return parent of parent process's ID
        printf("pid = fork() returned %d\n", pid);
        printf("Parent Of parent process, pid = %u\n",getppid());
        printf("parent process, pid = %u\n",getpid());

        // the parent process calls waitpid() on the child
        // waitpid() system call suspends execution of
        // calling process until a child specified by pid
        // argument has changed state
        // see wait() man page for all the flags or options
        // used here
        if (waitpid(pid, &status, 0) > 0)
        {    
            if (WIFEXITED(status) && !WEXITSTATUS(status))
                printf("program execution successful\n");
            
            else if (WIFEXITED(status) && WEXITSTATUS(status))
            {
                if (WEXITSTATUS(status) == 127) 
                    printf("execv failed\n");
                else
                    printf("program terminated normally, but returned a non-zero status\n");			
            }
            else
                printf("program didn't terminate normally\n");		
        }
        else 
        {
            printf("waitpid() failed\n");
        }
        printf("Press ENTER to quit");
        getchar();
        exit(0);
    }
    return 0;
}

/* OUTPUT

Before fork. getpid()=8822, getppid()=8427

After fork...
pid = fork() returned 8823
Parent Of parent process, pid = 8427
parent process, pid = 8822

After fork...
pid = fork() returned 0 (child process created)
child process, pid = 8823
parent of child process, pid = 8822
program execution successful
Press ENTER to quit
*/

