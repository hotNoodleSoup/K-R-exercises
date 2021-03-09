#include <stdio.h>

int bitcount(unsigned x);

void main(void)
{
	unsigned x = 176;
	printf("%d has %d bits\n", x, bitcount(x));
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x; x &= x-1)
		b++;
	
	return b;
}