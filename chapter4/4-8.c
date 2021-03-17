char buf = -1;  // buffer for ungetch

int getch(void)      // get a (possibly pushed back) character
{
  	if (buf != -1) {
		  int t;

		  t = buf;
		  buf = -1;

		  return t;
	} else
		return getchar();
}

void ungetch(int c)  // push back on input
{
  	if (buf != -1)
    		printf("you can't ungetch() twice in a row\n");
  	else
	  	buf = c;
}