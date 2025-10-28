#include "../../lib.h"

int intlen(int nbr)
{
	int i = 0;
	long n = nbr;
	if (n == 0)
		return 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return i;
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int len = intlen(nbr);
	char *s = malloc(len);
	if (!s) return 0;
	s[len] = 0;
	if (n == 0) s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		s[--len] = ("0123456789"[n % 10]);
		n /= 10;
	}
	return s;
}

int main()
{
	char *s = ft_itoa(12345);
	printf("%s", s);
	free(s);
}