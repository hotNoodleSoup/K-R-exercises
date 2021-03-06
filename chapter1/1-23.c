#include <stdio.h>
void rm_comment(void);

void main(void)
{
	rm_comment();
}

void rm_comment(void)
{
	int c;
	int temp;

	while ((c = getchar()) != EOF) {
		if (c == '\'') {
			putchar(c);
			while ((c = getchar()) != EOF) {
				if (c == '\\') {
					temp = c;
					if ((c = getchar()) != EOF) {
						putchar(temp);
						putchar(c);
					}
				} else if (c == '\'') {
					putchar(c);
					break;
				}
				else
					putchar(c);
			}

		} else if (c == '\"') {
			putchar(c);
			while ((c = getchar()) != EOF) {
				if (c == '\\') {
					temp = c;
					if ((c = getchar()) != EOF) {
						putchar(temp);
						putchar(c);
					}
				} else if (c == '\"') { 
					putchar(c);
					break;
				}
				else
					putchar(c);
			}
		} else if (c == '/') {
			temp = c;
			if ((c = getchar()) == EOF) {
				;
			} else if (c != '*') {
				putchar(temp);
				putchar(c);
			} else {
				while ((c = getchar()) != EOF) {
					if (c == '*')
						if ((c = getchar()) == '/')
							break;
					else 
						;	
				}
			}
		} else 
			putchar(c);
	}
}