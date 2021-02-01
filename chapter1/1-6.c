#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf( "\n"
                "c is a character"
                "\n");
    }
    printf("c is EOF\n");
}