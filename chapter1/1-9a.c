#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			while ((c = getchar()) == ' ')
				;
			if (c != EOF)
				putchar(c);
			else 
				return 0;
		} 
		else
			putchar(c);
	}

	printf("\n");
}