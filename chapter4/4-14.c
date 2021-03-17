#include <stdio.h>
#define swap(t, x, y) {t temp = x ; x = y ; y = temp;}

int main(void)
{
	float x = 3.14;
	float y = 9.99;

	swap(float, x, y)
	printf("x = %f, y = %f\n", x, y);

}