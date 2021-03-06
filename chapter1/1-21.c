#include <stdio.h>

//	Below structure is the key of my solution.
//	Thanks u/beej71!
//
// 	for (...) {
//		if(...) {
//			...
//			break;
//		}
//	}

void entab(int n);

int main(void)
{
        entab(8);
}

void entab(int n)
{
        int c;
        int i, j, k;
        int temp[n];
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