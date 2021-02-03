#include <stdio.h>

#define MAXREPEAT 35

main()
{
	int af[26] = {0};
	int c;
	int i, j;

	while ((c = getchar()) != EOF) {
		for (i = 'a'; i <= 'z'; ++i) 
			if (c == i || c == i - 32) {
				++af[i - 'a'];
				break;
			}
	}

	for (i = MAXREPEAT; i > 0; --i) {
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