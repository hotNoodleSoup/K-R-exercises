#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

void main(void)
{
	unsigned x = 349;
	int p = 6;
	int n = 4;
	printf("%d\n", invert(x, p, n));
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ ~(~0 << n) << p+1-n;
}