#include <stdio.h>
#define MAXLINE 20

int getline1(char s[], int max);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline1(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1) {
			printf("%s", line);
			continue;
		}
		
		while (len - 2 >= 0 && (line[len - 2] == ' ' || line[len - 2] == '\t')) {
			line[len - 2] = '\n';
			line[len - 1] = '\0';
			--len;
		}

		if (len == 1 && line[0] == '\n')
			continue;

		printf("%s", line);
	}
		
}

int getline1(char s[], int max)
{
	int c, i;

	i = 0;
	while(i < max - 1 && (c = getchar()) != '\n' && c != EOF) {
		s[i] = c; 
		++i;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}