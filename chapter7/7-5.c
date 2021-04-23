#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <string.h>

#define NUMBER '0'      /* signal that a number was found */

int getop(double *);
void push(double);
double pop(void);

/* reverse polish calculator */
int main(void)
{
	char type;
	double op2, n;

	while ((type = getop(&n)) != EOF) {
		switch (type) {
		case NUMBER:
			push(n);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
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
			printf("error: unknown command\n");
			break;
		}
	}
	return 0;
}

#define MAXVAL 100 /* max depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
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

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(double *n)
{
	char op;
        char s[100];

        printf("Input type: ");
        scanf("%s", s);

        if (!strcmp(s, "result"))
                return '\n';
        if (!strcmp(s, "op")) {
                printf("operator: ");
                if (scanf(" %c", &op) == 1)
                        return op;
                else
                        return 0;
        }
        if (!strcmp(s, "num")) {
                printf("number: ");
                if (scanf("%lf", n) == 1)
                        return NUMBER;
                else
                        return 0;
        }
        printf("expected result, op or num\n");
        return 0;
                
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters. buffer full\n");
	else
		buf[bufp++] = c;
}