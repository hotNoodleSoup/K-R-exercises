#include <stdio.h>

float toCel(float fahr);

main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f\t%5.1f\n", fahr, toCel(fahr));
		fahr = fahr + step;
	}
}

float toCel(float fahr)
{
	return 5 * (fahr -32) / 9.0;
}