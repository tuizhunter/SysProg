#ifndef OWNSTRING_H_
#define OWNSTRING_H_

struct node {
struct node *succ;
char *vorname;
char *nachname;
char* geburt;
char* wohnort;
};

int alphabet(struct node* head, char** kriterien, int decidek, int* offset, int ist);
int wohnort(struct node* head, char** kriterien, int decidek, int* offset, int ist);
int geburtstag(struct node* head, char** kriterien, int decidek, int* offset, int ist);
struct node* zuweisen(int (*sortFunction[])(struct node*, char**, int, int*, int),struct node* head, char** kriterien, int decidek, int* offset, int ist, int decidef);
char* read(int* z);
#endif