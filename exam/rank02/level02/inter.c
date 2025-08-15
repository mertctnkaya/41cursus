#include "../../lib.h"

char *ft_strchr(char *s, int c)
{
	while (1)
	{
		if (*s == (char) c)
			return (char *)s;
		if (*s == 0)
			break;
		s++;
	}
	return 0;
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return 1;
	}
	char memo[4096] = {0};

	int i = 0, j = 0;
	while (*av[1])
	{
		if (ft_strchr(av[2], *av[1]) && !ft_strchr(memo, *av[1]))
		{
			memo[i++] = *av[1];
			write(1, av[1], 1);
		}
		av[1]++;
	}
	write(1, "\n", 1);
}