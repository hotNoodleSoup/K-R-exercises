#include <stdio.h>

#define MAX 100

char *escape(char to[], char from[]);
char *unescape(char to[], char from[]);

void main(void)
{
	char arr[] = "1535\t35765\n";
	char destination1[MAX];
	char destination2[MAX];

	printf("%s to ", arr);
	printf("%s\n\n", escape(destination1, arr));

	printf("%s to ", destination1);
	printf("%s", unescape(destination2, destination1));
}

char *escape(char to[], char from[])
{
	int i;
	int j;

	for(i = j = 0; from[i] != '\0'; ++i)
		switch(from[i]) {
			case '\n': 
				to[j++] = '\\';
				to[j++] = 'n';
				break;
			case '\t' : 
				to[j++] = '\\';
				to[j++] = 't';
				break;
			default :
				to[j++] = from[i];
				break;
		}
	
	to[j] = '\0';
	return to;
}

char *unescape(char to[], char from[])
{
	int i;
	int j;

	for(i = 0, j = 0; from[i] != '\0'; ++i)
		switch(from[i]) {
			case '\\': 
				switch(from[++i]) {
					case 'n' :
						to[j++] = '\n';
						break;
					case 't' :
						to[j++] = '\t';
						break;
					default :
						to[j++] = '\\';
						to[j++] = from[i];
						break;
				}
				break;
			 default :
				to[j++] = from[i];
				break;
		}
	
	to[j] = '\0';
	return to;
}