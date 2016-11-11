#ifndef LIST_H_
#define LIST_H_



struct node* list_init(struct node* head, char* vorname, char* nachname);
struct node* list_add(struct node* head, char* vorname, char* nachname);
void list_print(struct node* head);
void list_remove(struct node* head);

#endif