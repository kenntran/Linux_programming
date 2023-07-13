#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>


void sig_handle(int signum)
{
	printf("Signal handler...\n");
	exit(EXIT_SUCCESS);
}


int main(int argc, char *argv[])
{
	sigset_t new_set, old_set;


	if(signal(SIGINT, sig_handle) == SIG_ERR)
	{
		fprintf(stderr, "Cannot hanlde SIGINT\n");
		exit(EXIT_FAILURE);
	}

	sigemptyset(&new_set);
	sigemptyset(&old_set);
	printf("empty new_set: %01X.\n", new_set);
	sigaddset(&new_set, SIGINT);
	//sigaddset(&new_set, SIGTERM);
	printf("new_set: %01X.\n", new_set);
	// if(sigprocmask(SIG_SETMASK, &new_set, &old_set) == 0)
	// {
	// 	if(sigismember(&new_set, SIGINT) == 1)
	// 	{
	// 		printf("SIGINT exist\n");
	// 		printf("signal mask: %01X.\n", old_set);
	// 	}
	// 	else if(sigismember(&new_set, SIGINT) == 0)
	// 	{
	// 		printf("SIGINT does not exist\n");
	// 	}
	// }

	if(sigprocmask(SIG_SETMASK, &new_set, &old_set) == 0)
	{
		sigprocmask(SIG_SETMASK, NULL, &old_set);
		for(int i = 1; i <= _NSIG; i++)
		{
			if(sigismember(&old_set, i) == 1)
			{
				printf("ID of block signal: %d\n", i);
			}
		}
		for(int i = _NSIG; i > 0 ; i--)
		{
			if(sigismember(&old_set, i) == 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		printf("old_set: %x\n",old_set);
	}
	//while(1);

	return 0;
}