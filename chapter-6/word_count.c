#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct lnode {
  char *word;
  int count;
  struct lnode *next;
};

struct tnode *addtree(struct tnode *, char *);
void treewalk(struct tnode *);
void insert(struct lnode *);
void listprint(struct lnode *);
int getword(char *, int);

struct lnode *head = NULL;

int main() {
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treewalk(root);
  listprint(head);
  return 0;
}

struct tnode *talloc(void);
struct lnode *lalloc(void);
char *my_strdup(char *);

struct tnode *addtree(struct tnode *p, char *w) {
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = my_strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }
  return p;
}

void treewalk(struct tnode *p) {
  if (p != NULL) {
    treewalk(p->left);
    struct lnode *temp = lalloc();
    temp->count = p->count;
    temp->word = p->word;
    insert(temp);
    treewalk(p->right);
  }
}

void listprint(struct lnode *p) {
  if (p != NULL) {
    printf("%4d %s\n", p->count, p->word);
    listprint(p->next);
  }
}

void insert(struct lnode *node) {
  if (head == NULL) {
    head = node;
  } else if (head->count < node->count) {
    node->next = head;
    head = node;
  } else {
    struct lnode *cur_node = head;
    while (cur_node->next != NULL && cur_node->next->count >= node->count)
      cur_node = cur_node->next;
    node->next = cur_node->next;
    cur_node->next = node;
  }
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct lnode *lalloc(void) {
  return (struct lnode *) malloc(sizeof(struct lnode));
}

char *my_strdup(char *s) {
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

int buf = -1;

int getch(void) {
  if (buf == -1) {
    return getchar();
  } else {
    int tmp = buf;
    buf = -1;
    return tmp;
  }
}

void ungetch(int c) {
  if (c == EOF)
    printf("ungetch: can't push back EOF\n");
  else if (buf != -1)
    printf("ungetch: already storing a character\n");
  else
    buf = c;
}

int getword(char *word, int lim) {
  int c;
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  else
    return c;
  while ((c = getch()) && lim-- > 0 && c != EOF && c != ' ' && c != '\t' && c != '\n')
    *w++ = c;
  if (c != EOF)
    ungetch(c);
  *w = '\0';
  return c;
}
