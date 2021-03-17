#include <stdio.h>

#define MAX 100

void itoa(int n, char s[]);

void main(void)
{
	char s[MAX];
	itoa(1212552, s);
	printf("%s\n", s);
}

void itoa(int n, char s[])
{
	static int i = 0;

	if (n < 0) {
		s[i++] = '-';
		n = -n;
	} 

	if (n / 10) 
		itoa(n / 10, s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}