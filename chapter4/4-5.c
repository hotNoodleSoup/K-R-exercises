#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>
#include <string.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number wes found
enum {
	SEE_TOP_STACK = 1000,
	CLEAR,
	SIN,
	COS,
	EXP,
	POW,
	SQRT,
	UNKNOWN
};

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
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case SQRT:
				push(sqrt(pop()));
				break;
			case UNKNOWN:
				printf("unknown instruction\n");
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
	if (isalpha(c)) {
		for (i = 1; isalpha(s[i] = getch()); ++i) 
			;
		ungetch(s[i]);
		s[i] = '\0';

		if (!strcmp("top", s))
			return SEE_TOP_STACK;
		else if (!strcmp("ac", s))
			return CLEAR;
		else if (!strcmp("sin", s))
			return SIN;
		else if (!strcmp("cos", s))
			return COS;
		else if (!strcmp("exp", s))
			return EXP;
		else if (!strcmp("pow", s))
			return POW;
		else if (!strcmp("sqrt", s))
			return SQRT;
		else
			return UNKNOWN;
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