#include <stdio.h>

char *mystrncat(char *s, char *t, int n);
char *mystrncpy(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main(void)
{
	char a[] = "11251251";
	char b[] = "a";
	
	mystrncpy(a, b, 4);
	printf("%c-%c-%c-%c-%c\n", *a, *(a+1), *(a+2), *(a+3), *(a+4));
}

char *mystrncat(char *s, char *t, int n)
{
	int k;
	char *first_location = s;

	while (*s != '\0')
		++s;
	
	k = 0;
	while (k++ < n && (*s++ = *t++) != '\0')
		;
	*s = '\0';
	
	return first_location;
}

char *mystrncpy(char *s, char *t, int n)
{
	int k;
	char *first_location = s;

	for (k = 0; k++ < n && (*s++ = *t++) != '\0'; )
		;
	while (k++ < n)
		*s++ = '\0';

	return first_location;
}

int mystrncmp(char *s, char *t, int n)
{
	int k;

	for (k = 0; k < n && *s == *t; s++, t++, k++)
		if (*s == '\0')
			return 0;
	
	if (n == 0 || n == k)
		return 0;
	else if (k < n)
		return *s - *t;
}