#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10

void *mycalloc(unsigned n, unsigned size);

int main(void)
{
    char *k;
    char *k1;
    if ((k = mycalloc(ARRAYSIZE, sizeof(int))) == NULL) {
        printf("calloc: can't bring memory");
        return 1;
    }

    for (k1 = k; k < k1 + ARRAYSIZE; k++)
        printf("%d ", *k);

    printf("\n");

}

void *mycalloc(unsigned n, unsigned size)
{
    char *p;
    char *p1;

    if ((p = malloc(n * size)) != NULL) {
        for (p1 = p; p1 < p + n * size; p1++)
            *p = 0;
    }

    return p;
}