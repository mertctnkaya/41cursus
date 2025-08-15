#include "../../lib.h"

void printbits(unsigned char n)
{
	int byte = 8;
	while (byte--)
		write(1, &(char []){(((n >> byte) & 1) + 48)}, 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return res;
}

int main()
{
	int a = 1;
	printbits(a);
	printf("\n");
	int n = reverse_bits(a);
	printbits(n);
	printf("\n%d", n);
}