#include <stdio.h>

int getfloat (double *pf);

int main(void)
{
	double n;
	int k;

	while(1) {		
		if ((k = getfloat(&n)) == EOF) {
			printf("\n");
			return 0;
		}
		else if (k != 0)
			printf("%f ", n);
	}
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pf)
{
	int c, sign;
	int exp;
	double val;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit(c = getch())) {
			ungetch(c);
			*pf = -1;
			return 0;
		}
	if (c == '.')
		if (!isdigit(c = getch())) {
			ungetch(c);
			return 0;
		} else {
			ungetch(c);
			c = '.';	
		}
	for (val = 0.0; isdigit(c); c = getch())
		val = 10 * val + (c - '0');
	if (c == '.') {
		for (exp = 1; isdigit(c = getch()); exp *= 10) 
			val = 10 * val + (c - '0');
		*pf = val / exp * sign;
	} else
		*pf = val * sign;
		
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