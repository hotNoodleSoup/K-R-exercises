#include <stdio.h>
#include <string.h>

#define MAXLINE	1000
	
int getline1 (char line[], int max);
int strrindex (char s[], char t[]);

char pattern[] = "ould";	/* Pattern "ould". */

int main ()
{
	char line[MAXLINE];
	int found = 0;

	while (getline1(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("%d %s", strrindex(line, pattern), line);
			found++;
		}
	return found;
}

int getline1 (char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j;
	int k;

	for (i = strlen(s) - 1; i >= 0; --i) {
		for (j = i, k = strlen(t) - 1; j >= 0 && k >= 0 && s[j] == t[k]; --j, --k)
			if (k == 0)
				return j;
	}

	return -1;
}