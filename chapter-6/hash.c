#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;
  return NULL;
}

char *my_strdup(char *s) {
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = my_strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void *) np->defn);
  }
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char *s) {
  struct nlist *np;
  struct nlist *previous = NULL;
  unsigned hashval = hash(s);
  for (np = hashtab[hashval]; np != NULL; previous = np, np = np->next)
    if (strcmp(s, np->name) == 0) {
      if (previous == NULL)
        hashtab[hashval] = np->next;
      else
        previous->next = np->next;
      free((void *) np->defn);
      free((void *) np->name);
      free((void *) np);
    }
}

void print_table() {
  struct nlist *np;
  for (int i = 0; i < HASHSIZE; i++)
    if (hashtab[i] != NULL)
      for (np = hashtab[i]; np != NULL; np = np->next)
        printf("%s: %s\n", np->name, np->defn);
}

int main() {
  install("1", "one");
  install("2", "two");
  install("3", "three");
  install("2", "Two");
  undef("1");
  print_table();
  return 0;
}
