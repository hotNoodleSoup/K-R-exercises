#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
        FILE *fp;
        char line[MAXLINE];
        int lineno;
        int page;
        
        if (argc == 1) {
                printf("Usage: 7-8.c fileopt1 fileopt2 ...\n");
        } else
                while (--argc) {
                        if ((fp = fopen(*++argv, "r")) == NULL) {
                                printf("error: can't open %s", *argv);
                                return 1;
                        }

                        printf("\t\t%s\n\n", *argv);

                        lineno = 1;
                        page = 0;
                        while (fgets(line, MAXLINE, fp) != NULL) {
                                printf("%s", line);
                                if (lineno % 30 == 0)
                                        printf("\n-----------------%d---------------\n\n", ++page);
                                lineno++;
                        }
                        
                        if (lineno % 30 != 1)
                                printf("\n-----------------%d---------------\n\n", ++page);
                        
                        fclose(fp);
                }
}