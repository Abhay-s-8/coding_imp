#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node{
        int data;
        struct node *next;

    };

    struct node *head=NULL,*temp, *newnode;

    int choice = 1;
    while (choice){
        newnode = (struct node*)malloc(sizeof(struct node));

        printf(
            "enter data :"
        );


        scanf("%d",&newnode->data);
        if(head == 0){
            head = temp = newnode;
        }
        else{
            temp->next= newnode;
            temp = newnode;
        }

        temp  -> next = head;
        printf("Do u Want to continue press 1 otherwise 0: ");
        scanf("%d",&choice);
    }

    printf("first node= %d",temp->next)
}