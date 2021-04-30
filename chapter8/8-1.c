#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 4096

void filecopy(int ifd, int ofd);

int main(int argc, char *argv[])
{
	int fd;

	if (argc == 1)
		filecopy(0, 1);
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fd, 1);
                printf("\n\n-------------------------------\n\n");
				close(fd);
			}
	return 0;
}

void filecopy(int ifd, int ofd)
{
	char buf[BUFSIZE];
    int n;

    while ((n = read(ifd, buf, BUFSIZE)) > 0)
        write(ofd, buf, n);
}