#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int lineinfo[50];
        int infoindex;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int line = 1;

// gcc 6-3.c getch.c
int main(void)
{
	struct tnode *root;
	char word[MAXWORD];
        int c;

	root = NULL;
	while ((c = getword(word, MAXWORD)) != EOF) {
                if (c == '\n')
                        line++;
		if (isalpha(word[0]) && strcmp(word, "a") && strcmp(word, "the") && strcmp(word, "and") && strcmp(word, "an") )
			root = addtree(root, word);
        }
	treeprint(root);

	return 0;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

        if ((c = getch()) == '\n')   
                return c;
        if (c == ' ' || c == '\t')
	        while ((c = getch()) == ' ' || c == '\t')
		        ;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

struct tnode *talloc(void);
char *mystrdup(char *s);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->infoindex = 0;
                p->lineinfo[p->infoindex] = line;
		p->left = p-> right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
                if (p->lineinfo[p->infoindex] != line) {
		        p->infoindex++;
                        p->lineinfo[p->infoindex] = line;
                }
        }
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
                int i;

		treeprint(p->left);
		printf("%s: ", p->word);
                for (i = 0; i <= p->infoindex; i++)
                        printf("%d%s", p->lineinfo[i], i != p->infoindex ? ", " : "");
                printf("\n");
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}