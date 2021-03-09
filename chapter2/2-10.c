#include <stdio.h>

int lower(int c);

void main(void)
{
	printf("%c to %c\n%c to %c\n", 'A', lower('A'), 'b', lower('b'));
}

int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}