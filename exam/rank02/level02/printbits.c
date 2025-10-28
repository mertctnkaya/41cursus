#include "../../lib.h"

void printbits(unsigned char n)
{
	/* int bit = 8;
	while (bit--)
	{
		unsigned char c = ((n >> bit) & 1) + 48;
		write(1, &c, 1);
	} */

	int byte = 8;
	while (byte--)
		write(1, &(char []){(((n >> byte) & 1) + 48)}, 1);
}

int main()
{
	printbits(97);
}