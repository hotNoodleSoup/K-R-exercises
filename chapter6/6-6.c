#define HASHSIZE 101
#define MAXLEN 100

// I omitted a lot of error checking
// 1. All #define directives should be at the top like above.
// 2. The program doesn't consider about string literals, character constants, comments.
// 3. It even converts macro name in #define directive.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};



static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
int getword(char *word, int lim, FILE *fp);

int main(void)
{
        FILE *fp;

        fp = fopen("6-6.c", "r");
        if (fp == NULL) {
                perror("Error in opening file");
                return 0;
        }

        int c;
        char name[MAXLEN];
        char defn[MAXLEN];
        char *p = defn;
        while ((c = fgetc(fp)) == '#') {
                getword(name, MAXLEN, fp); // pass define 
                if (!strcmp(name, "define")) {
                        getword(name, MAXLEN, fp);
                        fgetc(fp);

                        do {
                                *p = fgetc(fp);
                                p++;
                        } while (*(p - 1) != '\n');
                        
                        *(p - 1) = '\0';
                        install(name, defn);
                        p = defn;
                }
        }
        
          
        fclose(fp);

        fp = fopen("6-6.c", "r");
        if (fp == NULL) {
                perror("Error in opening file");
                return 0;
        }

        struct nlist *np;
        while ((c = fgetc(fp)) != EOF) {
                if (!isalpha(c))
                        putchar(c);
                else {
                        ungetc(c, fp);
                        getword(name, MAXLEN, fp);
                        if ((np = lookup(name)) != NULL)
                                printf("%s", np->defn);
                        else
                                printf("%s", name);
                }     
        }

        fclose(fp);
}

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name)
{
	struct nlist *pp, *np;

	for (pp = NULL, np = hashtab[hash(name)]; 
		np != NULL; 
		pp = np, np = np->next)

		if (!strcmp(name, np->name)) {
			if (pp == NULL)
				hashtab[hash(name)] = np->next;
			else
				pp->next = np->next;

			free(np->name);
			free(np->defn);
			free(np);

			return;
		}
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