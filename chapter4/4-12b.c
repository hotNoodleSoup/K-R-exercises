#include <stdio.h>
#include <string.h>

struct strinfo {
	int position;
};

void itoa (int n, char s[], struct strinfo* sp);

int main ()
{
	char s[20];

	struct strinfo info_s = { 0 };
	struct strinfo *sp = &info_s;

	itoa(-1321672, s, sp);
	printf("%s\n", s);
}

void itoa (int n, char s[], struct strinfo* sp)
{
	if (n < 0) {
		s[sp->position++] = '-';
		n = -n;
	}

	if (n / 10)
		itoa(n / 10, s, sp);
	s[sp->position++] = n % 10 + '0';
	s[sp->position] = '\0';
}