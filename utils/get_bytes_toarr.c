#include <stdio.h>
#include <stdlib.h>

// getbytes long, short, int

int missing2(int *arr, int n)
{
	int i = 1;
	while (i <= n)
	{
		if (arr[i - 1] ^ i)	return i;
		i++;
	}
}
void printbits(unsigned char c)
{
	int i;
	for (i = 7; i >= 0; i--)
	{
		printf("%d", (c >> i) & 1);
	}
	printf("\n");
}
int main(void)
{
	unsigned char a = 4;
	unsigned char b = 5;
	printbits(a);
	printbits(b);
	printf("\n");
	unsigned char c = a ^ b;
	printbits(c);
	unsigned char d = a & b;
	printbits(d);
	unsigned char e = a | b;
	printbits(e);
	unsigned char f = ~a;
	printbits(f);
}
