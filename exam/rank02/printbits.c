#include "../lib.h"

void printbits(unsigned char n)
{
	int byte = 8;
	while (byte--)
		printf("%d", (n >> byte) & 1);
}

int main()
{
	printbits(97);
}