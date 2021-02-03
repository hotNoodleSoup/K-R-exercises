#include <stdio.h>
#define MAXLENGTH 10
#define MAXREPEAT 35
#define IN 1
#define OUT 0

main()
{
	int c;
	int wc[MAXLENGTH] = {0};
	int count = 0;
	char state = OUT;

	while((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z' || c>= 'A' && c<= 'Z') {
			state = IN;
			++count;
		}
		else if (state == IN) {
			state = OUT;
			++wc[count - 1];
			count = 0;
		}
	}
	
	int i, j;

	for (i = MAXREPEAT; i >= 1; --i) {
		printf("%2d |", i);
		for (j = 0; j < 10; ++j) {
			if (wc[j] == i) {
				printf(" | ");
				--wc[j];
			}
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("   " "*" "----------" "----------" "----------" "\n");
	printf("   ");
	for (i = 1; i <=10; ++i)
		printf( "%3d", i);

	printf("\n");
}