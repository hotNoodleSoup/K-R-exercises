#include <stdio.h>

main()
{
    int celsius, fahr;
    int lower, upper, step;

    /* No floating-point needed */

    lower = -20;
    upper = 100;
    step = 10;

    printf("celsius fahr\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = 9 * celsius / 5 + 32;
        printf("%7d %4d\n", celsius, fahr);
        celsius = celsius + step;
    }
}