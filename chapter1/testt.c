#include <ctype.h>
#include <limits.h>
#include <stdio.h>

/*  print a graph of the frequencies of different characters */

#define GRAPH_HEIGHT 20
#define AA (3 * UCHAR_MAX/4) 
#define BB (4 * UCHAR_MAX/4)

void count_chars(FILE *in, unsigned int *frequencies)
{
    int c;
    while ((c = fgetc(in)) != EOF) {
        ++frequencies[(unsigned char)c];
    }
}

void print_graph(FILE *out, const unsigned int *frequencies)
{
    /* start at 1 to avoid division by 0 later */
    unsigned int max = 1;
    for (unsigned int i = 0;  i <= UCHAR_MAX;  ++i) {
        if (frequencies[i] > max) {
            max = frequencies[i];
        }
    }

    /* print characters on a graph */
    for (unsigned int i = GRAPH_HEIGHT;  i > 0;  --i) {
        fprintf(out, "%2d |", i);
        for (int c = AA;  c <= BB;  ++c) {
         
            char bar = frequencies[c] >= i * max / GRAPH_HEIGHT ? '|' : ' ';
            fprintf(out, " %c ", bar);
        }
        fputs("\n", out);
    }

    /* print the base line */
    fputs("   +", out);
    for (int c = AA;  c <= BB;  ++c) {
       
        fputs("---", out);
    }
    fputs("\n   ", out);
    for (int c = AA;  c <= BB;  ++c) {
        
        fprintf(stdout, "%3c", c);
    }
    fputs("\n", out);
}

int main(void)
{
    unsigned int af[UCHAR_MAX+1] = {0};
    count_chars(stdin, af);
    print_graph(stdout, af);
}