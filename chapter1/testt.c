#include <stdio.h>

main()
{
	int c, prevc = EOF;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || prevc != ' ')
  		  putchar(c);
		prevc      =             c;
	}

                   printf("\n");
}
