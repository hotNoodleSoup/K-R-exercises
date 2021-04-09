// Should be compiled as gcc 5-13.c mygetline.c alloc.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEFAULT_LINE_NUMBER 10
#define MAX_LINEINPUT 150

int mygetline(char s[], int lim);
char *alloc(int n);

int main(int argc, char *argv[])
{
        int nline;

        /* If argument is erroneous, it is ignored. */
        
        nline = DEFAULT_LINE_NUMBER;
        if (argc == 2 && *argv[1]++ == '-' && isdigit(*argv[1]))
	        nline = atoi(argv[1]);

        char *lineptr[nline];
        char *p;
        char tmpline[MAX_LINEINPUT];
        int len;
        int lineindex;

        lineindex = 0;
        while ((len = mygetline(tmpline, MAX_LINEINPUT)) > 0) {
                if ((p = alloc(len)) != NULL) {
                        if (lineindex == nline) {
                                lineindex = 0;
                                tmpline[len - 1] = '\0';
                                strcpy(p, tmpline);                                
                                lineptr[lineindex++] = p;
                        } else {
                                tmpline[len - 1] = '\0';
                                strcpy(p, tmpline);
                                lineptr[lineindex++] = p;
                        }
                }
        }
        
        int i;               
        for (i = lineindex; i < nline; i++) 
                printf("%s\n", lineptr[i]);

        for (i = 0; i < lineindex; i++)
                printf("%s\n", lineptr[i]);

}