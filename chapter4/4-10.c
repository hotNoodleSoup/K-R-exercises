#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number wes found

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
 	int type;
 	double op2;
  	char s[MAXOP];

 	while ((type = getop(s)) != EOF) {
    		switch (type) {
			case NUMBER:
		  		push(atof(s));
	  			break;
			case '+':
		  		push(pop() + pop());
	  			break;
			case '-':
		  		op2 = pop();
	  			push(pop() - op2);
	  			break;
			case '*':
	  			push(pop() * pop());
	  			break;
			case '/':
		  		op2 = pop();
		  		if (op2 != 0.0)
	    				push(pop() / op2);
				else
					printf("error: zero divisor\n");
	  			break;
			case '\n':
	  			printf("\t%.8g\n", pop());
	  			break;
			default:
	  			printf("error: unknown command %s\n", s);
	  			break;
		}
  	}  
 	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
	    	val[sp++] = f;
  	else
    		printf("error: stack full, con't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  	if (sp > 0)
    		return val[--sp];
  	else {
      		printf("error: stack empty\n");
      		return 0.0;
    	}
}

#include <ctype.h>

#define MAXLINE 3000

int getline1 (char s[], int lim);

int index1 = -1;
char get[MAXLINE];

/* getop: get next operator or numberic operand */
int getop(char s[])
{
 	int c;
	int i;

	if (index1 == -1)
		if(!getline1(get, MAXLINE))
			return EOF;
		else
			index1 = 0;

  	while ((s[0] = c = get[index1++]) == ' ' || c == '\t')
    		;
  	s[1] = '\0';
  	if (!isdigit(c) && c != '.') {
		if(c == '\n') {
			index1 = -1;
    			return c;    // not a number
		} else
			return c;
	}
  	i = 0;
  	if (isdigit(c))              // collect integer part
    		while (isdigit(s[++i] = c = get[index1++]))
      			;
  	if (c == '.')                // collect fraction part
	    	while (isdigit(s[++i] = c = get[index1++]))
      			;
  	s[i] = '\0';
  	--index1;
  	return NUMBER;
}

int getline1 (char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}