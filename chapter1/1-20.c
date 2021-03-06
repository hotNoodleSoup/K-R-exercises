#include <stdio.h>

void detab(int num);

int main(void)
{
	detab(10);
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
}