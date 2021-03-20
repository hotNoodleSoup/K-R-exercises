#include <stdio.h>

#define SIZE 20

int getint (int *pn);

int main(void)
{
	int n;
	int array[SIZE] = { 0 };

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	for (n = 0; n < 20; n++)
		printf("%d  ", array[n]);

	printf("\n");
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit(c = getch())) {
			ungetch(c);
			*pn = -1;
			return 0;
		}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free posotion in buf

int getch(void)      // get a (possibly pushed back) character
{
  	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push back on input
{
  	if (bufp >= BUFFSIZE)
    		printf("ungetch: too many characters\n");
  	else
	  	buf[bufp++] = c;
}