#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char output[1024];
	int fd;
	int file_size, num_read, num_write;


	fd = open("./example.txt", O_RDWR | O_CREAT, 0677);
	if(-1 == fd)
	{
		printf("open() failed\n");
	}
	file_size = read(fd, output, sizeof(output));
	printf("%s\n", output);
	printf("..............\n");


	lseek(fd, 0, SEEK_SET);
	write(fd, "modification...", strlen("modification..."));
	lseek(fd, 0, SEEK_CUR);
	write(fd, output, strlen(output));
	close(fd);

	return 0;
}




