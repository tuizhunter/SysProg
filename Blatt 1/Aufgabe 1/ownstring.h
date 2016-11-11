#ifndef OWNSTRING_H_
#define OWNSTRING_H_

struct node {
struct node *succ;
char *vorname;
char *nachname;
};

int alphabet(struct node* test, char* vorname, char* nachname);

char* read(int* z);
#endif