#include <stdio.h>
#define MAXLINE 20

int getline1(char line[], int maxline);
void copy(char to[], char fromp[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline1(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("max length : %d\n\t%s", max, longest);
	return 0;		
}

int getline1(char s[], int lim)
{
	int c, i;
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2)
			s[i] = c;
	
	if (i < lim - 1) {
		s[i] = '\n';
		s[i + 1] = '\0';
	}
	else {
		s[lim - 2] = '\n';
		s[lim - 1] = '\0';
	}

	if (i == 0 && c == '\n')
		return 1;

	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}