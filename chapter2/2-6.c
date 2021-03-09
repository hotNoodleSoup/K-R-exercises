#include <stdio.h>
unsigned getbits(unsigned x, int p, int n, unsigned y);

void main(void)
{
	unsigned x = 113;
	int p = 5;
	int n = 3;
	unsigned y = 26;
	printf("%u\n", getbits(x, p, n, y));
}

unsigned getbits(unsigned x, int p, int n, unsigned y)
{
	return ~(~(~0 << n) << p-n+1) & x | (y & ~(~0 << n)) << p-n+1;
}