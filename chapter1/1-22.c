#include <stdio.h>
#define TABWIDTH 8

void fold(int n);

int main(void)
{
	fold(20);
}

void fold(int n)
{
	int column;
	int c;

	column = 0;
	while ((c = getchar()) != EOF) {
		putchar(c);
		if (c == '\t') {
			column = column + TABWIDTH - (column % TABWIDTH);
		} else if (c == '\n') {
			column = 0;
		} else {
			++column;
		}

		if (column >= n && c != '\t' && c!= ' ') {
			printf("\\\n");
			column = 0;
		}
	}
}