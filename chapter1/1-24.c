#include <stdio.h>

/* This program checks if there is unbalanced parentheses, curly braces or brackets.
 * This program doesn't check if there is a newline charcter between a single quote or a double quote.
 * This program doesn't check if there is non-terminated comment, single quote or double quote.
 */

#define NOTHING 	0
#define COMMENT 	1
#define SINGLE_QUOTE 	2
#define DOUBLE_QUOTE 	3

#define PARENTHESIS	1
#define CURLY_BRACE	2
#define BRACKET		3

#define MAX_NESTING_LEVEL 100

void check_paren(void);

void main(void)
{
	check_paren();
}

void check_paren(void)
{
	int c;
	int line;
	int state;
	int nest[MAX_NESTING_LEVEL] = {NOTHING};
	int n;

	n = 0;
	line = 1;
	state = NOTHING;
	while ((c = getchar()) != EOF) {
		if (n > MAX_NESTING_LEVEL -1) {
			printf("error : line %d : exceed MAX_NESTING_LEVEL\n", line);
			return;
		} else if (c == '\n') {
			++line;
		} else if (state != COMMENT) {
			if (c == '/') 
				if ((c = getchar()) == '*')
					state = COMMENT;
		}
		
		if (state == NOTHING && n == 0) {
			if (c == '\'')
				state = SINGLE_QUOTE;
			else if (c == '\"')
				state = DOUBLE_QUOTE;
			else if (c == '(')
				nest[n++] = PARENTHESIS;
			else if (c == '{')
				nest[n++] = CURLY_BRACE;
			else if (c == '[')
				nest[n++] = BRACKET;
			else if (c == ')') {
				printf("error : line %d : unmatched )\n", line);
				return;
			} else if (c == '}'){
				printf("error : line %d : unmatched }\n", line);
				return;
			} else if (c == ']'){
				printf("error : line %d : unmatched ]\n", line);
				return;
			}
		} else if (state == NOTHING && nest[n-1] == PARENTHESIS) {
			if (c == ')')
				nest[--n] = NOTHING;
			else if (c == '(')
				nest[n++] = PARENTHESIS;
			else if (c == '[')
				nest[n++] = BRACKET;
			else if (c == '\'')
				state = SINGLE_QUOTE;
			else if (c == '\"')
				state = DOUBLE_QUOTE;
			else if (c == '}') {
				printf("error : line %d : ( + }\n", line);
				return;
			}
			else if (c == ']') {
				printf("error : line %d : ( + ]\n", line);
				return;
			}
		} else if (state == NOTHING && nest[n-1] == CURLY_BRACE) {
			if (c == '}')
				nest[--n] = NOTHING;
			else if (c == '(')
				nest[n++] = PARENTHESIS;
			else if (c == '{')
				nest[n++] = CURLY_BRACE;
			else if (c == '[')
				nest[n++] = BRACKET;
			else if (c == '\'')
				state = SINGLE_QUOTE;
			else if (c == '\"')
				state = DOUBLE_QUOTE;
			else if (c == ')') {
				printf("error : line %d : { + )\n", line);
				return;
			}
			else if (c == ']') {
				printf("error : line %d : { + ]\n", line);
				return;
			}
		} else if (state == NOTHING && nest[n-1] == BRACKET) {
			if (c == ']')
				nest[--n] = NOTHING;
			else if (c == '(')
				nest[n++] = PARENTHESIS;
			else if (c == '\'')
				state = SINGLE_QUOTE;
			else if (c == ')') {
				printf("error : line %d : [ + )\n", line);
				return;
			}
			else if (c == '}') {
				printf("error : line %d : [ + }\n", line);
				return;
			}
		} else {
			if (state == COMMENT && c == '*') {
				if ((c = getchar()) == '/') 
					state = NOTHING;
			} else if (c == '\\') 
				getchar();
			else if (state == SINGLE_QUOTE && c == '\'') 
				state = NOTHING;
			else if (state == DOUBLE_QUOTE && c == '\"') 
				state = NOTHING;
		}
	}
}