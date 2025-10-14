#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd1;
	// int fd2;
	// int fd3;
	char *line;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening file");
		return 1;
	}
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	// fd2 = open("test2.txt", O_RDONLY);
	// if (fd2 < 0)
	// {
	// 	perror("Error opening file");
	// 	return 1;
	// }
	// fd3 = open("test3.txt", O_RDONLY);
	// if (fd3 < 0)
	// {
	// 	perror("Error opening file");
	// 	return 1;
	// }
	// while ((line = get_next_line(fd1)) != NULL)
	// {
	// 	printf("fd1 %s", line);
	// 	free(line);
	// }
	// while ((line = get_next_line(fd2)) != NULL)
	// {
	// 	printf("fd2 %s", line);
	// 	free(line);
	// }
	// while ((line = get_next_line(fd3)) != NULL)
	// {
	// 	printf("fd3 %s", line);
	// 	free(line);
	// }
	// printf("\nEnd of file reached.\n");
	if (close(fd1) < 0)
	{
		perror("Error closing file");
		return 1;
	}
	// if (close(fd2) < 0)
	// {
	// 	perror("Error closing file");
	// 	return 1;
	// }
	// printf("File closed successfully.\n");
	return 0;
}
