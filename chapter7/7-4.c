#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

void minscanf(char *fmt, ...);

int main(void)
{
        int c[124];
        int d;

	minscanf(" %s, %d", &c, &d);
        printf("%s, %d", c, d);
}

void minscanf(char *fmt, ...)
{
	va_list ap;
        int i;
        int input;
        char *p;
	char *c;
        int *ival;
        char num[100];

	va_start(ap, fmt);
	for(p = fmt; *p; p++) {
                if (*p == ' ' || *p == '\t') {
                        while (isspace(input = getchar()))
                                ;
                        ungetc(input, stdin);
                } else if (*p != '%') {
                        if (*p != getchar()) {
                                printf("error: matching failure\n");
                                return;
                        }
                } else {
                        switch(*++p) {
                        case 'c':
                                c = va_arg(ap, char *);
                                *c = getchar();
                                break;
                        case 's':
                                while(isspace(input = getchar()))
                                        ;
                                c = va_arg(ap, char *);
                                for (*c++ = input; !isspace(*c = getchar()); c++) // assume an input string
                                        ;                                         // ends with a whitespace character.
                                *c = '\0';
                                break;
                        case 'd':
                                while(isspace(input = getchar()))
                                        ;
                                ival = va_arg(ap, int *);
                                if (!isdigit(input)) {
                                        printf("error: %d expects a digit\n");
                                        return;
                                }
                                for (num[0] = input, i = 1; isdigit(num[i] = getchar()); i++)
                                        ;
                                ungetc(num[i], stdin);
                                num[i] = '\0';
                                *ival = atoi(num);
                                break;
                        default:
                                putchar(*p);
                                break;
                        }
                }
        }
        va_arg(ap, int);

	va_end(ap);
}
