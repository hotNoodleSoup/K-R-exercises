#include <stdio.h>

unsigned rightrot(unsigned x, int n);

void main(void)
{
	unsigned x = 15;
	int n = 3;

	printf("%u\n", rightrot(x, n));
}

unsigned rightrot(unsigned x, int n)
{
	int i;
	unsigned k;

	for (i = 1, k = ~0; k = k >> 1; ++i)
		;
	
	return x << i-n | x >> n; // or x << sizeof(unsigned) * CHAR_BIT - n | x >> n;
}