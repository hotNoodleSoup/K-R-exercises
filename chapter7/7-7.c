#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
        FILE *fp;
	char line[MAXLINE];
        char *pattern;
	
        pattern = argv[1];
        if (argc == 1) {
                printf("Usage: 7-7.c pattern file1opt1 fileopt2 ...");
                return 1;
        } else if (argc == 2) {
                while (fgets(line, MAXLINE, stdin) != NULL) {
                        line[strlen(line) - 1] = '\0';
                        if (strstr(line, pattern) != NULL)
                                printf("%s\n", line);
                }
                return 0;
        } else {
                argc -= 1;
                argv += 1;
                while (--argc) {
                        if ((fp = fopen(*++argv, "r")) == NULL) {
                                printf("error: can't open %s", *argv);
                                return 1;
                        }

                        printf("\t\t%s\n\n", *argv);

                        while (fgets(line, MAXLINE, fp) != NULL) {
                                line[strlen(line) - 1] = '\0';
                                if (strstr(line, pattern) != NULL)
                                        printf("%s\n", line);
                        }

                        printf("\n---------------------------------------------\n");

                        fclose(fp);
                }
        }

	
	return 0;
}