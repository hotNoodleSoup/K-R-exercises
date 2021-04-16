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
        struct nlist *np;

        if ((np = lookup(name)) == NULL)
                return;

        struct nlist *prev;
        unsigned hashval;

        hashval = hash(name);
        if (hashtab[hashval] == np && np->next == NULL) {
                hashtab[hashval] = NULL;
                free(np->name);
                free(np->defn);
                free(np);

                return;
        }

        for (prev = hashtab[hashval]; prev->next != np; prev = prev->next)
                ;

        if (hashtab[hashval] == np) {
                hashtab[hashval] = np->next;
                free(np->name);
                free(np->defn);
                free(np);
        } else {
                prev->next = np->next;
                free(np->name);
                free(np->defn);
                free(np);
        }