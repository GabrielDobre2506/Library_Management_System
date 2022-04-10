#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "list.h"

int main(){
    int choice;
    int counter=0;
    struct node *head = NULL;
    char new_name_book[MAX];
    char new_name_author[MAX];
    do{
        counter++;
        if(counter != 0){
            printf("\n");
        }
        printf("----1. Add a book\n----2. Search author\n----3. Search book\n----4. Exit\n\n");
        printf("----Enter your choice:");
        scanf("%d", &choice);
        system("cls");
        getchar();
        switch(choice){
            system("CLS");
            case 1: {//in this case the user adds a new book to the list
                printf("Enter the name of the author:...\n");
                fgets(new_name_author,MAX,stdin);
                printf("Enter the name of the book:...\n");
                fgets(new_name_book,MAX,stdin);
                append(&head, new_name_author, new_name_book);
                break;
            }
            case 2: {//in this case the program lists all the books depending on the name of the author
                printf("Enter the name of the author: ");
                fgets(new_name_author,MAX,stdin);
                search(head, new_name_author, 2);
                break;
            }
            case 3: {//in this case the program lists all the authors depending on the title of the book
                printf("Enter the name of the book: ");
                fgets(new_name_book,MAX,stdin);
                search(head, new_name_book, 3);
                break;
            }
            case 4: {//if the user inputs 4 the program will close
                exit(0);
            }
            default://if the user inputs another value then the program will
                printf("\n----Sorry, invalid choice!\n");
                printf("\n----Press any key to continue\n");
                getchar();
                break;
        }
    }while(choice!=4);
    return 0;
}

