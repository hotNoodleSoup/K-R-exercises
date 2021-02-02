#include <stdio.h>

/* 	With the loose definition, a word is any sequence of characters
	that does not contain a blank, tab or newline. */

#define ON 1
#define OFF 0

main()
{
	int c, state;

	state = OFF;

	while((c = getchar()) != EOF) {
		if (state == ON && (c == ' ' || c == '\n' || c == '\t')) {
			
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			state = ON;
			printf("\n");
		}
		else if (state == OFF) {
			putchar(c);
		}
		else {
			state = OFF;
			putchar(c);
		}
	}

	printf("\n");
}