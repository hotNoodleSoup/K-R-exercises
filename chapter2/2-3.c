#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

void main(void)
{
	char hex[] = "0x1a";
	
	printf("%s = %d\n", hex, htoi(hex));
}

int htoi(char s[])
{
	int c;
	int i;
	int k;
	int exp;
	int num;

	k = 0;
	if (s[0] == 0) {
		if (s[1] == 'x' || s[1] == 'X') {
			for (i = 2; s[i] == '\0'; ++i)
				++k;
		}
	}
	else 
		for(i = 0; s[i] != '\0'; ++i)
			++k;
	
	for (num = 0, exp = 1; k != 0 && s[k-1] != 'x' && s[k-1] != 'X'; --k) {
		if (isdigit(s[k-1]))
			num = num + (s[k-1] - '0') * exp;
		else
			num = num + tolower(s[k-1]) -'a' + 10;

		exp = exp * 16;
	}

	return num;
}