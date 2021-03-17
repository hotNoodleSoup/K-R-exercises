#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	char s[] = "1231.13e-5";

	printf("%.8f\n", atof(s));
}

double atof(char s[])
{
	double val, power;
	int i, sign;
	int exp, esign;

	for (i = 0; isspace(s[i]); ++i) // skip white space
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;

	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + s[i] - '0';

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E') {
		esign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			++i;
		for(exp = 0; isdigit(s[i]); ++i)
			exp = 10 * exp + s[i] - '0';
		if(esign == 1)
			for ( ; exp > 0; --exp)
				power /= 10;
		else
			for ( ; exp > 0; --exp)
				power *= 10;
	}
	
	return val = sign * val / power;
}