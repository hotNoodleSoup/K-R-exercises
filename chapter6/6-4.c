#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *next;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void sort_list(struct tnode *);
int getword(char *, int);

// gcc 6-4.c getch.c
int main(void)
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

        sort_list(root);
	treeprint(root);

	return 0;
}

void sort_list(struct tnode *current)
{
        struct tnode *index;
        int temp;
        char tempword[MAXWORD];

        if (current == NULL)
                return;
        
        while (current != NULL) {
                index = current->next;

                while (index != NULL) {
                        if (current->count < index->count) {
                                temp = current->count;
                                current->count = index->count;
                                index->count = temp;

                                strcpy(tempword, current->word);
                                strcpy(current->word, index->word);
                                strcpy(index->word, tempword);
                        }
                        index = index->next;
                }
                current = current->next;
        }
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
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
		p->count = 1;
		p->next = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else 
                p->next = addtree(p->next, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->next);
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