// gcc 5-19.c getch.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
#define NONE -1

int gettoken(void);

int tokentype;	// type of last token
char token[MAXTOKEN];	// last token string
char out[1000];	// output string

int main(void)
{
	int type;
        int last;
        char temp[MAXTOKEN];

        last = NONE;
        while (gettoken() != EOF) {
                strcpy(out, token);
                while ((type = gettoken()) != '\n')
                        if (type == PARENS || type == BRACKETS) {
                                if (last == '*') {
                                        sprintf(temp, "(%s)", out);
                                        strcat(temp, token);
                                        strcpy(out, temp);
                                        last = type;
                                } else {
                                        strcat(out, token);
                                        last = type;
                                }
                        } else if (type == '*') {
                                sprintf(temp, "*%s", out);
                                strcpy(out, temp);
                                last = type;
                        } else if (type == NAME) {
                                sprintf(temp, "%s %s", token, out);
                                strcpy(out, temp);
                                last = type;
                        } else
                                printf("invalid input at %s\n", token);
                printf("%s\n", out);
        }

	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}