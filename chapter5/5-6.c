#include <stdio.h>

int mygetline(char *s, int lim)
{
	char *first_location = s;
	int c;

	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	
	return s - first_location;
}

int atoi(char *s)
{
	int n;

	for (n = 0; *s >= '0' && *s <= '9'; s++)
		n = 10 * n + (*s - '0');
	return n;
}

void reverse(char *s)
{
	int c;
	char *first = s;

	while (*s)
		s++;
	
	s--;
	for (; first < s; first++, s--) {
		c = *first;
		*first = *s;
		*s = c;
	}
}

void itoa(int n, char *s)
{
	char *first_location = s;
	int sign;

	if ((sign = n) < 0)
		n = -n;
	
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(first_location);
}

int strindex(char *s, char *t)
{
	char *initial_s = s;
	char *a;
	char *b;

	for ( ; *s; s++) {
		for (a = s, b = t; *b && *a == *b; a++, b++)
			;
		if (b - t > 0 && !*b)
			return s - initial_s;
	}
	return -1;
}

#define NUMBER 1000
 
int getop(char *s)
{
 	int i, c;

  	while ((*s = c = getch()) == ' ' || c == '\t')
    		;
  	*(s+1) = '\0';
  	if (!isdigit(c) && c != '.')
    		return c;                  // not a number
  	i = 0;
  	if (isdigit(c))              // collect integer part
    		while (isdigit(*++s = c = getch()))
      			;
  	if (c == '.')                // collect fraction part
	    	while (isdigit(*++s = c = getch()))
      			;
  	*s = '\0';
  	if (c != EOF)
    		ungetch(c);
  	return NUMBER;
}