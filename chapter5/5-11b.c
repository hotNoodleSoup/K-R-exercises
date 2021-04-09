#include <stdio.h>
#include <stdlib.h>

#define MAXSTOPS 100
#define DEFAULT_TABSIZE 8

void detab(int nstops, int *stops, int m, int n);

int main(int argc, char *argv[])
{
    int nstops;
    int stops[MAXSTOPS];

    argc--;
    argv++;

    for (nstops = 0; nstops < argc && nstops < MAXSTOPS; nstops++)
        stops[nstops] = atoi(argv[nstops]);

    detab(nstops, stops, nstops ? stops[nstops - 1] : 0, DEFAULT_TABSIZE);
}

void detab(int nstops, int *stops, int m, int n)
{
    int c;
    int stop;
    int column;

    column = stop = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\t') {
            putchar(c);

            if (c == '\n')
                column = stop = 0;
            else {
                column++;
                if (stop < nstops && stops[stop] == column)
                stop++;
            }
        } else {
            if (column < stops[stop]) {
                while (column++ < stops[stop]) 
                    putchar(' ');

                column--;
                if (stop < nstops)
                    stop++;
            } else {
                int i;

                i = n - (column - m) % n;

                do {
                    putchar(' ');
                    column++;
                } while (--i);               
            }
        } 
    }

}