#include <stdio.h>
#include <string.h>

#define MAXLINE 100 + 1

int main(int argc, char *argv[])
{
        FILE *fp1, *fp2;
        char arr1[MAXLINE], arr2[MAXLINE];
        
        if (argc != 3) {
                printf("error: expected 3 argrments\n");
                return 1;
        }

        if ((fp1 = fopen(argv[1], "r")) == NULL) {
                printf("error: failed to open %s\n", argv[1]);
                return 1;
        }
        if ((fp2 = fopen(argv[2], "r")) == NULL) {
                printf("error: failed to open %s\n", argv[2]);
                return 1;
        }

        for (;;) {
                if (fgets(arr1, MAXLINE, fp1) == NULL) {
                        if (feof(fp1)) {
                                printf("EOF reached in %s\n", argv[1]);
                                return 0;
                        } else {
                                printf("error occured while getting contents in %s\n", argv[1]);
                                return 1;
                        }
                }

                if (fgets(arr2, MAXLINE, fp2) == NULL) {
                        if (feof(fp2)) {
                                printf("EOF reached in %s\n", argv[2]);
                                return 0;
                        } else {
                                printf("error occured while getting contents in %s\n", argv[2]);
                                return 1;
                        }
                }

                if (strcmp(arr1, arr2)) {
                        printf("first different lines in %s and %s\n", argv[1], argv[2]);
                        printf("%s\n", arr1);
                        printf("%s\n", arr2);
                        return 0;
                }
        }
}