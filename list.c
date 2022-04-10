#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define MAX 256

void append(struct node** head, char new_name_author[MAX], char new_name_book[MAX])//this function inserts another node to the end of the list
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head;

    strcpy(new_node->name_author,new_name_author);
    strcpy(new_node->name_book,new_name_book);

    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void search(struct node* head, char key_name[MAX],int choice)//this function lists all the book titles or the name of the authors depending on the choice of the user
{
    int i=0,sum1=0,sum2=0;
    struct node *current = (struct node*)malloc(sizeof(struct node));
    current = head;
    if(choice==2) {//if the user's choice is 2 then the program will list all the books that were written by a certain author
        if(current!=NULL) {
            while (current != NULL) {//in this loop the program will verify that the key name and the author's name that already exists in the list are the same
                sum1=0;
                sum2=0;
                for(i=0;i<strlen(current->name_author);i++){
                    if((int)current->name_author[i]!=32){
                        sum1+=(int)current->name_author[i];
                    }
                }
                for(i=0;i<strlen(key_name);i++){
                    if((int)key_name[i]!=32) {
                        sum2 += (int) key_name[i];
                    }
                }
                if(sum1==sum2){//if the sum of all the characters in the key name is equal to the sum of all the characters in the author's name then it will print the book title
                    printf("%s ", current->name_book);
                    printf("\n");
                }
                current = current->next;
            }
        }
        else if(current==NULL)//if the key name does not exist in the list
        {
            printf("Author not found");
        }
    }
    if(choice==3) {
        if(current!=NULL) {
            while (current != NULL) {//if the user's choice is 3 then the program will list the authors that wrote a certain book
                sum1=0;
                sum2=0;
                for(i=0;i<strlen(current->name_book);i++){
                    if((int)current->name_book[i]!=32){
                        sum1+=(int)current->name_book[i];
                    }
                }
                for(i=0;i<strlen(key_name);i++){
                    if((int)key_name[i]!=32) {
                        sum2 += (int) key_name[i];
                    }
                }
                if(sum1==sum2){//if the sum of all the characters in the key name is equal to the sum of all the characters in the book's name then it will print the author's name
                    printf("%s ", current->name_author);
                    printf("\n");
                }
                current = current->next;
            }
        }
        else if(current==NULL)//if the key name does not exist in the list
        {
            printf("Author not found");
        }
    }
}
