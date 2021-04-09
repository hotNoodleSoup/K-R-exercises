// gcc 5-16.c alloc.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, 
           int (*comp)(void *, void *));

int mystrcmp(const char *s, const char *t);
int numcmp(const char *, const char *);
void reverse (char *s[]);

int fold = 0;
int directory = 0;

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
        int reversal = 0;
        int c;

        while (--argc > 0 && (*++argv)[0] == '-') {
                while (c = *++argv[0])
	        switch(c) {
                        case 'n' : 
                                numeric = 1;
                                break;
                        case 'r' :
                                reversal = 1;
                                break;
                        case 'f' :
                                fold = 1;
                                break;
                        case 'd' :
                                directory = 1;
                                break;
                        default :
                                printf("%c : illegal option", c);
                                return 0;
                }
        }

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort((void **) lineptr, 0, nlines-1,
			(int (*)(void*, void*))(numeric ? numcmp : mystrcmp));

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

#define MAXLEN 10000

int readlines(char *lineptr[], int maxlines)
{
	int mygetline(char *, int);
	char *alloc(int);

	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
        
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int mygetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
                if (fold == 1)
                        *t++ = tolower(c);
		else
                        *t++ = c;
        }

	if (c == '\n')
		*t++ = c;

	*t = '\0';
	return t - s;
}

int mystrcmp(const char *s, const char *t)
{
	char a, b;

        int test = 0;;
		
	for ( ; ; ) {
		
		a = *s++;
		b = *t++;

                if (directory == 1) {
                        if ((isalnum(a) || a == ' ') && (isalnum(b) || b == ' ')) {
                               if (a != b)
                                        break;
                        } else if (a == '\0')
                                        return 0;
                } else
                        if (a != b)
                                break;
		        else if (a == '\0')
                                return 0;
	}
        
	return a - b;
}