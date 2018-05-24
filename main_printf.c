#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd = 42;
	char *a = "";
	int b = 0;

	while (get_next_line(fd, &a) == 1)
	{
		printf("ligne %d:%s\n", b, a);
	}

}
