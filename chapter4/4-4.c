#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number wes found
#define SEE_TOP_STACK 1000
#define CLEAR 1001

int getop(char []);
void push(double);
double pop(void);
void see_top_stack(void);
void clear_stack(void);

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
			case SEE_TOP_STACK:
				see_top_stack();
				break;
			case CLEAR:
				clear_stack();
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
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
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

void see_top_stack(void)
{
	if (sp > 0)
		printf("top element of current stack is %g\n", val[sp-1]);
	else {
		printf("stack is empty\n");
	}
}

void clear_stack(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand */
int getop(char s[])
{
 	int i, c;

  	while ((s[0] = c = getch()) == ' ' || c == '\t')
    		;
  	s[1] = '\0';
	if (c == 't') {
		if ((c = getch()) == 'o') {
			if ((c = getch()) == 'p')
				return SEE_TOP_STACK;
			else {
				ungetch(c);
				return c;
			}
		} else {
			ungetch(c);
			return c;
		}
	} else if (c == 'a') {
		if ((c = getch()) == 'c')
			return CLEAR;
		else {
			ungetch(c);
			return c;
		}
	} else if (!isdigit(c) && c != '.')
    		return c;                  // not a number
  	i = 0;
  	if (isdigit(c))              // collect integer part
    		while (isdigit(s[++i] = c = getch()))
      			;
  	if (c == '.')                // collect fraction part
	    	while (isdigit(s[++i] = c = getch()))
      			;
  	s[i] = '\0';
  	if (c != EOF)
    		ungetch(c);
  	return NUMBER;
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