#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'   // signal that a number wes found

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand */
int getop(char s[])
{
 	int i, c;
	static int pushback = -1;

	if (pushback != -1) {
		s[0] = c = pushback;
		pushback = -1;
	} else
		s[0] = c = getch();

  	while (c == ' ' || c == '\t')
    		s[0] = c = getch();
  	s[1] = '\0';
  	if (!isdigit(c) && c != '.')
    		return c;                  // not a number
  	i = 0;
  	if (isdigit(c))              // collect integer part
    		while (isdigit(s[++i] = c = getch()))
      			;
  	if (c == '.')                // collect fraction part
	    	while (isdigit(s[++i] = c = getch()))
      			;
	if (c != EOF)
		pushback = c;
  	s[i] = '\0';
  	return NUMBER;
}