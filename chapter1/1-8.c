#include <stdio.h>

main()
{
	int c, blank, tab, nl;

	blank = tab = nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blank;
		else if (c == '\t')
			++tab;
		else if (c == '\n')
			++nl;
	}

	printf( "blank = %d\n"
			"tab = %d\n"
			"nl = %d\n", blank, tab, nl);
}