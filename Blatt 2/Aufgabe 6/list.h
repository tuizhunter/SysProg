#ifndef LIST_H_
#define LIST_H_

struct node* list_init(struct node* head);
struct node* list_add(struct node* last, struct node* new, struct node* follow);
void list_print(struct node* head);
void list_remove(struct node* head);

#endif