#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free posotion in buf

int getch(void)      // get a (possibly pushed back) character
{
  	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push back on input
{
  	if (bufp >= BUFFSIZE)
    		printf("ungetch: too many characters\n");
  	else
	  	buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	for (i = 0; s[i]; ++i)
		ungetch(s[i]);
}