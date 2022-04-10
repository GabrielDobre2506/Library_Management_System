#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define MAX 256

struct node{
    char name_book[MAX];
    char name_author[MAX];
    struct node *next;
};

void append(struct node** head, char new_name_author[MAX], char new_name_book[MAX]);
void search(struct node* head, char key_name[MAX],int choice);

#endif // LIST_H_INCLUDED
