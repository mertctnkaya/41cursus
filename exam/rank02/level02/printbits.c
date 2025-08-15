#include "../../lib.h"

void printbits(unsigned char n)
{
	int byte = 8;
	while (byte--)
		write(1, &(char []){(((n >> byte) & 1) + 48)}, 1);
}

int main()
{
	printbits(97);
}