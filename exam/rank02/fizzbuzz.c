#include "../lib.h"

void putnbr(int num)
{
	if (num > 9)
		putnbr(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

int main(int ac _u, char **av _u)
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("fizzbuzz");
		else if (i % 3 == 0)
			printf("fizz");
		else if (i % 5 == 0)
			printf("buzz");
		else
			putnbr(i);
		printf("\n");
	}
	return 0;
} 