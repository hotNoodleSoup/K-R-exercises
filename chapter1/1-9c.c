#include <stdio.h>

main()
{
	int c;
	char flag = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && flag == 0) {
			putchar(c);
			flag = 1;
		}
		else if (c == ' ' && flag == 1) {
			
		}
		else if (flag == 0) {
			putchar(c);
		}
		else {
			putchar(c);
			flag = 0;
		}	
	}

	printf("\n");
}