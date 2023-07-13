#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void func(int signum)
{
	printf("Prevent zombie process\n");
	printf("value: %d\n", signum);
	wait(NULL);
}

int main(int agrc, char *agrv[])
{
	pid_t child_pid, child_id;
	int status, rv;
	int counter = 2;

	child_pid = fork();
	if (child_pid >= 0)
	{
		if(child_pid == 0) //child
		{
			printf("process ID_1 of child: %d\n", getpid());
			printf("process ID_2 of parent: %d\n", getppid());
			//while(1);
			sleep(5);
			exit(0);

		}else //!= 0 ==> parent
		{
			printf("I'm parent\n");
			printf("process ID of parent: %d\n", getpid());
			//rv = wait(&status);
			// rv = waitpid(child_pid, &status, 0);
			// if(rv == -1)
			// {
			// 	printf("waitpid unsuccessful\n");
			// }
			// else
			// {
			// 	printf("PID child process: %d\n",rv);
			// }
			signal(SIGCHLD, func);			
			//sleep(20);
			while(1);
			if(WIFEXITED(status))
			{
				printf("Normally termination, status = %d\n", WEXITSTATUS(status));
			}else if(WIFSIGNALED(status))
			{
				printf("killed by signal, status = %d\n",WTERMSIG(status));
			}
		}
	}
	else
	{
		printf("fork error\n");
	}

	return 0;
}