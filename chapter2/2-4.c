#include <stdio.h>

void squeeze(char s1[], char s2[]);

void main(void)
{
	char a[] = "12345678912";
	char b[] = "12364678234";

	squeeze(a, b);
	printf("%s\n", a);	
}	

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = j = 0; s1[i]; i++) {
		for (k = 0; s2[k] && s1[i] != s2[k]; k++)
			;

		if (s2[k] == '\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}