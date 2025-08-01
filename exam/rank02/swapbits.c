#include "../lib.h"

unsigned char swapbits(unsigned char n)
{
	return (n >> 4) | (n << 4);
}