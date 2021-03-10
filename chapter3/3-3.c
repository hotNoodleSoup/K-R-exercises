#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char *expand(char from[], char to[]);

void main(void)
{	
	char to[MAX];
	char arr[] = "g-1e2-rtk z-a 1-4-9";
	printf("%s\n", expand(arr, to));
}

char *expand(char from[], char to[])
{
	int i, j;
	int c;

	for (i = j = 0; from[i] != '\0'; ++i) {
		if (isalnum(from[i]) && from[i + 1] == '-' && isalnum(from[i + 2])) {
			if ((isupper(from[i]) && isupper(from[i + 2])
				|| islower(from[i]) && islower(from[i + 2])
				|| isdigit(from[i]) && isdigit(from[i + 2]))
			&& from[i] < from[i + 2]) {
				for (c = from[i]; c < from[i + 2]; ++c)
					to[j++] = c;
				i += 1;
			} else {
				to[j++] = from[i++];
				to[j++] = from[i];
			}
		} else
			to[j++] = from[i];
	}

	to[j] = '\0';
	return to;
}