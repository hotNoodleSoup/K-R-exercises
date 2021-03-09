#include <stdio.h>

int any(char s1[], char s2[]);

void main(void)
{
	char a[] = "52421415";
	char b[] = "dsgjiop1grt";

	printf("first location of %c is %d\n", b[any(a, b)], any(a, b));
}

int any(char s1[], char s2[])
{
	int i;
	int j;

	for (i = 0; s2[i]; ++i) {
		for (j = 0; s1[j]; ++j) {
			if (s1[j] == s2[i])
				return i;
		}
	}

	return -1;
}