// The idea is the same as 6-5a.c, but undef() in here is very well formed.
// I brought it from https://github.com/anotherlin/tcpl/blob/master/chapter_6/exercise_6-5.c.

#include <stdio.h>

struct nlist {
        struct nlist *next;
        char *name;
        char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

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