#include <stdio.h>
#define MAXLINE 1000

void reverse(char to[], char from[], int n);
int getline1(char line[], int max);

main()
{
	int i;
	char templine[MAXLINE];
	char arrivline[MAXLINE];

	while((i = getline1(templine, MAXLINE)) > 0) {
		reverse(arrivline, templine, i);
		printf("%s", arrivline);
	}

}

void reverse(char to[], char from[], int n)
{
	int i;
	n = n - 2;

	for (i = 0; n >= 0; ++i, --n) {
		to[i] = from[n];
	}

	to[i] = '\n';
	to[i + 1] = '\0';
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

// another solution
// 		just declare one one array in main, and reverse forth and back.