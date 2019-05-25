//this just invloves printing inreverse order without changing the direction of pointers
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void printList(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertRev( int x){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    if(head != NULL){
        //traverse the list till end
        while(temp != NULL){
            temp = temp->next;
        }
        temp1->data = x;
        temp->next = temp1;
        temp1->next = NULL;
    } else {
        temp->data = x;
        temp->next = NULL;
    }
}


int main(){


    //created list
    insertRev(5);
    insertRev(7);
    insertRev(6);
    insertRev(2);
    insertRev(1);

    
    printf("\nThe list is : ");
    printList();

    return 0;
}