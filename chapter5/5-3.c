#include <stdio.h>

char *strcat(char *s, char *t);

int main(void)
{
	char a[100] = "agssagd ";
	char b[] = "4hh24wdg";
	printf("%s\n", strcat(a, b)); 
}

char *strcat(char *s, char *t)
{
	char *first_location = s;

	while (*s != '\0')
		++s;
	while ((*s++ = *t++) != '\0')
		;
	
	return first_location;
}