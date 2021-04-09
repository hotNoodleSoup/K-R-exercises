#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TABSTART 0
#define DEFAULT_TABSIZE 8

void detab(int m, int n);

int main(int argc, char *argv[])
{
        int n;
        int start;
        int size;

        argc--;
        argv++;

        start = DEFAULT_TABSTART;
        size = DEFAULT_TABSIZE;
        while (argc > 0) {
                if (**argv == '-') 
                        start = -atoi(*argv);
                else if(**argv == '+') 
                        size = atoi(*argv);

                argc--;        
                argv++;
        }
        
        detab(start, size);
        return 0;
}

void detab(int m, int n)
{
	int column;
	int c;
        int i;

        for (i = 0; i < m; i++)
                putchar(' ');

	column = m;
	while ((c = getchar()) != EOF) {
		if (c != '\t')
			if (c == '\n') {
				column = m;
				putchar(c);

                                for (i = 0; i < m; i++)
                                putchar(' ');
			} else {
				++column;
				putchar(c);
			}
		else 
			do {
				++column;
				putchar(' ');
			} while (column % n);
	}
}