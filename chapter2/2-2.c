#include <stdio.h>
#define MAX 10

void main(void)
{
	int c;
	int i;
	int lim = MAX + 1;
	char s[lim];

	i = 0;
	while (1) {
		if (i < lim - 1) {
			if((c = getchar()) != '\n') {
				if (c != EOF)
					s[i] = c;
				else
					break;
			} else
				break;
		} else 
			break;

		++i;
	}
}