#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd, len;
	char buf[1024]={0};
	fd = open("test01.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	len = read(fd, buf, sizeof(buf));
	printf("read: %s\n", buf);

	printf("read again\n");
	lseek(fd, 0, SEEK_SET);
	memset(buf, '\0', len);
	len = read(fd, buf, sizeof(buf));
	printf("read %d, content:%s\n", len, buf);
	close(fd);

	return 0;
}
