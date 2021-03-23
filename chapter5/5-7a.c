// This should be compiled as : gcc 5-7.c mygetline1.c

#include <stdio.h>
#include <string.h>

#define MAXLINES 500
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines, char line[][MAXLEN]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void)
{
	int nlines;
    char line[MAXLINES][MAXLEN];

	if ((nlines = readlines(lineptr, MAXLINES, line)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000

int mygetline1(char [][MAXLEN], int, int);

int readlines(char *lineptr[], int maxlines, char line[][MAXLEN])
{
	int len, nlines;
    int a;

    a = 0;
	nlines = 0;
	while ((len = mygetline1(line, a++, MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			line[a-1][len-1] = '\0';
			lineptr[nlines++] = line[a-1];
		}

	return nlines;
}

#define MAXLEN 1000

int mygetline1(char s[][MAXLEN], int a, int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[a][i++] = c;
	if (c == '\n')
		s[a][i++] = c;
	s[a][i] = '\0';
	return i;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}