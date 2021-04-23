#include <stdio.h>
#include <ctype.h>

#define TABSIZE 8
#define LINELENGTH 30

int main(void)
{
        int c;
        int column;

        column = 0;
        while((c = getchar()) != EOF) {
                if (c == '\t')
                        if (column >= LINELENGTH) {
                                printf("\n%c", c);
                                column = TABSIZE;
                        } else {
                                putchar(c);
                                column += TABSIZE - column % TABSIZE; 
                        }
                else if (c == '\n') {
                        putchar(c);
                        column = 0;
                } else if (iscntrl(c)) {
                        if (column >= LINELENGTH) {
                                printf("\n'\\%x'", c);
                                if (c >= 0 && c < 10)
                                        column = 3 + 1;
                                else if (c >= 10 && c < 100)
                                        column = 3 + 2;
                                else if (c >= 100 && c <= 127)
                                        column = 3 + 3;
                        } else {
                                printf("'\\%x'", c);
                                if (c >= 0 && c < 10)
                                        column = 3 + 1;
                                else if (c >= 10 && c < 100)
                                        column = 3 + 2;
                                else if (c >= 100 && c <= 127)
                                        column = 3 + 3;
                        }

                } else {
                        if (column >= LINELENGTH) {
                                printf("\n%c", c);
                                column = 1;
                        } else {
                                putchar(c);
                                column++;
                        }
                }

        }
}