/* I can't understand the purpose of this exercise.
 * The program already handle EOF character well althought it's done by getop(). 
 */

#include <stdio.h>

#define BUFSIZE	100
int	eof_pushedback = 0;
char	buf[BUFSIZE];
int	bufp = 0;

int getch (void)
{
	if (eof_pushedback) {
		eof_pushedback = 0;
		return EOF;
	} else 
		return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
	if (c == EOF)
		eof_pushedback = !0;
	else if (bufp >= BUFSIZE)
		printf("Error: Too many characters!\n");
	else
		buf[bufp++] = c;
}