#include <stdio.h>

int binsearch(int x, int v[], int n);

void main(void)
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("%d is %dth character\n", 31, binsearch(31, v, 10));
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low < high) {
		mid = (low+high) / 2;
		if (x > v[mid])
			low = mid + 1;
		else
			high = mid;
	}

	if (v[low] == x)
		return low;
	else
		return -1;
}