#include <stdio.h>

int strend(char *s, char *t);

int main(void)
{
	char a[] = "wv45hvhw45vwh45 1121234123413221";
	char b[] = "1234123413221";
	printf("%d\n", strend(a, b)); 
}

int strend(char *s, char *t)
{
	int n;

	while (*s)
		s++;

	for (n = 0; *t; n++)
		t++;
	
	while (n--)
		if (*--s != *--t)
			return 0;
	
	return 1;
}