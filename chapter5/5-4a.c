#include <stdio.h>

int strend(char *s, char *t);

int main(void)
{
	char a[] = "wv45hvhw45vwh45 11234123413221";
	char b[] = "1234123413221";
	printf("%d\n", strend(a, b)); 
}

int strend(char *s, char *t)
{
	char *temps, *tempt;

	for (; *s; s++) {
		for (temps = s, tempt = t; *temps++ == *tempt++; )
			if (*tempt == '\0' && *temps == '\0')
				return 1;
	}

	return 0;
}