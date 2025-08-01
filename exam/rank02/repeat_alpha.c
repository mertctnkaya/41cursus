#include "../lib.h"

char tolow(char c)
{
	if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int isalpha(int a)
{
	return ((a >= 97 && a <= 122) || (a >= 65 && a <= 90));
}

int main(int ac, char **av)
{
	if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
	int i = -1;
	while (av[1][++i])
	{
		if (isalpha(av[1][i]))
		{
			int x = tolow(av[1][i]) - 'a' + 1;
			for (int j = 0; j < x; j++)
				write(1, &av[1][i], 1);
		}
		else
		{
			write(1, &av[1][i], 1);
		}
	}
	return 0;	
}