// copy from https://github.com/anotherlin/tcpl/blob/master/chapter_7/exercise_7-1.c
// I couldn't understand the intention of this exercise. Is it useful in any case?

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int c;

	while ((c = getchar()) != EOF)

		/* Depending of the system, argv[0] may contain the full
		 * calling path of the program.  The simplest solution is to
		 * use strstr() to search for the name.  This is not perfect
		 * however.
		 */ 

		putchar(strstr(argv[0], "lower") != NULL 
			? tolower(c) 
			: toupper(c));
	
	return 0;
}