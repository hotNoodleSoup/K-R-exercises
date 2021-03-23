#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXVAL 100

double atof(char *s);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int i, count;
    char c;

    char opbuffer[MAXVAL - 1];

    count = 0;
    i = 0;

    while (--argc > 0 && isdigit(**++argv)) {
        push(atof(*argv));
        count++;
    }
    
    --argv;
    ++argc;

    while (--argc > 0)
        if ((*++argv)[1] == '\0') {
            if ((c = **argv) == '+' || c == '-' || c == '/' || c == '*')
                opbuffer[i++] = c;
            else {
                printf("illegal parameter\n");
                return 1;
            }
        } else {
            printf("illegal parameter\n");
            return 1;
        }

    double temp;  
    int j;

    if (count != i + 1)
        printf("Number of operators and operands doesn't match\n");
    else
        for (j = 0; j < i; ++j)
            switch (opbuffer[j]) {
                case '+' :
                    push(pop() + pop());
                    break;
                case '-' :
                    temp = pop();
                    push(pop() - temp);
                    break;
                case '/' :
                    temp = pop();
                    push(pop() / temp);
                    break;
                case '*' :
                    push(pop() * pop());
                    break;
            }
    printf("%lf\n", pop());
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

double atof(char *s)
{
	double val, power;
	int i, sign;
	int exp, esign;

	for (i = 0; isspace(s[i]); ++i) // skip white space
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;

	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + s[i] - '0';

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E') {
		esign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			++i;
		for(exp = 0; isdigit(s[i]); ++i)
			exp = 10 * exp + s[i] - '0';
		if(esign == 1)
			for ( ; exp > 0; --exp)
				power /= 10;
		else
			for ( ; exp > 0; --exp)
				power *= 10;
	}
	
	return val = sign * val / power;
}