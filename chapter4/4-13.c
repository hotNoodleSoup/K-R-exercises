#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

void reverse(char s[], int n);
void itoa(int n, char s[]);

void main(void)
{
	char s[MAX];
	itoa(12345, s);
	printf("%s\n", s);
}

void reverse(char s[], int n) 	// The seconde argument should be always 1.
{				// The function should be always called as reverse(s, 1);
	int temp;
	int len;

	len = strlen(s);
	if ((len + 1) / 2 > n)
		reverse(s, n + 1);
	
	temp = s[n-1];
	s[n-1] = s[(len - 1) - (n-1)];
	s[(len - 1) - (n-1)] = temp;
}

void itoa(int n, char s[])
{
	int i, sign;

	i = 0;

	if ((sign = n) < 0) {
		if (n == INT_MIN) {
			n = -(n + 1);
			s[i++] = n % 10 + 1 + '0';
			n /= 10;
		} else
			n = -n;
	}
	
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s, 1);
}