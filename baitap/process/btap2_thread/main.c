#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <pthread.h>


// int main(int agrc, char *agrv[])
// {
// 	int i = 0;
// 	int fd;
// 	clock_t start,end;
// 	double exec;
	
// 	fd = open("./example", O_RDWR | O_CREAT, 0677);

// 	start = clock();
// 	while(i < 100000)
// 	{
// 		write(fd, "A", 1);
// 		i++;
// 	}
// 	end = clock();
// 	printf("execution time: %lf s\n", (double)(end-start)/CLOCKS_PER_SEC);
// 	close(fd);
// 	return 0;
// }


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

typedef struct{
	int fd;
}thread_args_t;

static void *handle_th(void *args)
{
	thread_args_t *thr = (thread_args_t *)args;
	pthread_mutex_lock(&lock);
	while(counter < 100000)
	{
		write(thr->fd, "A", 1);
		counter++;
	}
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
	int ret;
	thread_args_t thr;
	pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7, thread_8, thread_9, thread_10;
	clock_t start, end;
	double exec;

	memset(&thr, 0, sizeof(thread_args_t));

	thr.fd = open("./example", O_RDWR | O_CREAT, 0677);

	start = clock();
	if( ret = pthread_create(&thread_1, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_2, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_3, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_4, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_5, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_6, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_7, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_8, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_9, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	if( ret = pthread_create(&thread_10, NULL, &handle_th, &thr))
	{
		printf("pthread_create error number: %d\n", ret);
		return -1;
	}

	
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_join(thread_4, NULL);
	pthread_join(thread_5, NULL);
	pthread_join(thread_6, NULL);
	pthread_join(thread_7, NULL);
	pthread_join(thread_8, NULL);
	pthread_join(thread_9, NULL);
	pthread_join(thread_10, NULL);

	end = clock();
	printf("execution time: %lf s\n", (double)(end-start)/CLOCKS_PER_SEC);
	close(thr.fd);
	return 0;
}

