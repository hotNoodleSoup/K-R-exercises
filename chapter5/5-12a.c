#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TABSTART 0
#define DEFAULT_TABSIZE 8

void entab(int m, int n);

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
        entab(start, size);

        return 0;
}

void entab(int m, int n)
{
        int c;
        int i, j, k, l;
        int temp[n];

        for (l = 0; l < m; l++)
                printf(" ");
	k = 0;
        while (1) {

                for (i = 0; i < n; ++i) {
        	        temp[i] = getchar();
                        if (temp[i] == EOF) {
                                if (i > 0)
                                        for (j = 0; j < i; ++j)
                                                putchar(temp[j]);
                                break;
                        } else if (temp[i] == '\n') {
                                for (j = 0; j <= i; ++j)
                                        putchar(temp[j]);
                                for (l = 0; l < m; l++)
                                        printf(" ");
                                break;
			} else if (temp[i] == '\t') {
				for (j = 0; j <= i; ++j)
                                        putchar(temp[j]);
				break;
                        }
                }

                if (temp[i] == EOF)
                        break;
                if (temp[i] == '\n')
                        continue;
		if (temp[i] == '\t')
			continue;

                if (temp[n-1] != ' ') {
                        for (i = 0; i <= n-1; ++i)
                                putchar(temp[i]);
                } else {
                        for (k = n-2; k >= 0; --k) {
                                if (temp[k] != ' ') {
                                        for (i = 0; i <= k; ++i)
                                                putchar(temp[i]);
                                        putchar('\t');
                                        break;
                                }
                        }
                }
                if (k == -1) {
                        putchar('\t');
                        k = 0;
  	  	}
 	}

       	printf("\n");
}