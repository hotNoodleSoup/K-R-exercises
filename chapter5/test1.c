#include <stdio.h>
#include <ctype.h>

void detab(int num);
int atoi(char s[]);

int main(int argc, char *argv[])
{
	if (argc == 1)
       	detab(10);
	else if (argc == 2)
		detab(atoi(*++argv));
	else
		printf("Can't accept arguments more than one\n");
}

void detab(int num)
{
	int column;
	int c;

	column = 0;
	while ((c = getchar()) != EOF) {
		if (c != '\t')
			if (c == '\n') {
				column = 0;
				putchar(c);
			} else {
				++column;
				putchar(c);
			}
		else 
			do {
				++column;
				putchar(' ');
			} while (column % num);
	}

    printf("\n");
}

int atoi(char s[])
{
	int i, n, sign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}