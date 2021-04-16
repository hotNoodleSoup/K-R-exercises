#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void tree_work(char *a[]);
int getword(char *, int, FILE *fp);

int main(int argc, char *argv[])
{
        char **argvcpy;

        argvcpy = argv;
        if (argc == 7) {
                while (--argc > 0) {
                        if (!isalpha((*++argvcpy)[0])) {
                                printf("Make sure if each argument starts with an alphabet.");
                                return 1;
                        }
                }
        } else {
                printf("You should pass exactly 6 arguments");
                return 1;
        }

        int i;
        for (i = 1; i <= 6; i++)
                tree_work(argv + i);
}

void tree_work(char *a[])
{
        struct tnode *root;
        char word[MAXWORD];
        FILE *fp;

        fp = fopen("6-2.c", "r");
        if (fp == NULL) {
                perror("Error in opening file");
                exit(0);
        }

        root = NULL;
        while (getword(word, MAXWORD, fp) != EOF)
                if (isalpha(word[0]) && strncmp(*a, word, strlen(*a)) == 0)
                        root = addtree(root, word);

        fclose(fp);
        treeprint(root);
        printf("----------------------------------------------------------------\n");
}

int getword(char *word, int lim, FILE *fp)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = fgetc(fp))) {
			ungetc(*w, fp);
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
		p->left = p-> right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
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