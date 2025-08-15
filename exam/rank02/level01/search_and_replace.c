#include "../../lib.h"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*av[1])
	{
		if (*av[1] == *av[2])
			*av[1] = *av[3];
		write(1, *av[1], 1);
		av[1]++;
	}
	write(1, "\n", 1);
	return 0;
}