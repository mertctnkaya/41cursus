#include "../../lib.h"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return 1;
	}
	int len = 0, i = 0;
	while(av[1][len])
		len++;
	while (i < len && *av[2])
	{
		if (av[1][i] == *av[2]++)
			i++;
	}
	if (i == len)
		write(1, av[1], len);
	write(1, "\n", 1);
}