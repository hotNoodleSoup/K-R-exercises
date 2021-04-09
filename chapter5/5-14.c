// gcc 5-14.c readlines-writelines.c alloc.c

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, 
           int (*comp)(void *, void *));

int numcmp(const char *, const char *);
void reverse (char *s[]);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
        int reversal = 0;

        while (--argc > 0) {
	        if ((*++argv)[0] == '-')
                        if ((*argv)[1] == 'n')
                                numeric = 1;
                        else if ((*argv)[1] == 'r')
                                reversal = 1;
        }
		
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort((void **) lineptr, 0, nlines-1,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));
                if (reversal == 1)
                        reverse(lineptr);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void myqsort(void *v[], int left, int right,
			int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	myqsort(v, left, last-1, comp);
	myqsort(v, last+1, right, comp);
}

#include <stdlib.h>

int numcmp(const char *s1, const char *s2)
{
        double v1, v2;

        v1 = atof(s1);
        v2 = atof(s2);
        if (v1 < v2)
                return -1;
        else if (v1 > v2)
                return 1;
        else   
                return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void reverse (char *s[])
{
	int i, j;
        char *c;

	i = 0;

	for (j = 0; s[j] != '\0'; j++)
		;

        j--;

	if (j > 1)
		while (i < j) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;

			i++;
			j--;
		}
} 