#include <stdio.h>

/* 	print a graph of the frequencies of different characters */

#define GRAPH_HEIGHT 5

main()
{
	int af[26] = {0};
	int max = 1;
	int c;
	int i, j;

	/* get characters */
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') 
			if (++af[c - 'a'] > max) {
				++max;
				continue;
			}
		if (c >= 'A' && c <= 'Z')
			if (++af[c - 'A'] > max)
				++max;
	}

	/* calculate relative frequencies */
	for (i = 0; i < 26; ++i) {
		af[i] = GRAPH_HEIGHT * af[i] / max;
	}

	/* print character frequencies on a graph */
	for (i = GRAPH_HEIGHT; i > 0; --i) {
		printf("%2d |", i);
		for (j = 'a'; j <= 'z'; ++j) {
			if (af[j - 'a'] == i) {
				printf(" | ");
				--af[j - 'a'];
			}
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("   " "*" "---------------" "---------------" "---------------" "---------------" "---------------" "---"  "\n");
	printf("   ");
	for (i = 'a'; i <= 'z'; ++i) {
		printf("%3c", i);
	}

	printf("\n");
}