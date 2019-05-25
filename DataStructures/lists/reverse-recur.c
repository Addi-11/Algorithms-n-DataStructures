//reverse the directions of all pointers
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head ;

void printRevList(struct Node *p){

   if(p == NULL) return;
   printRevList(p->next);
   printf("%d ",p->data);

}

void printList(){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    printf("\nThe list is: ");
    while( temp != NULL){

        printf("%d ",temp->data);
        temp = temp->next; 
    }
}

int insert( int x){
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x; 
    
    if(head != NULL){
       temp->next = head;
    } else{
       temp->next = NULL;
    }
    head = temp;

}

int main(){
    
    insert(4);
    insert(8);
    insert(6);
    insert(1);
    insert(7);
    insert(3);
    insert(2);

    printf("\nList: ");
    printList();

    printf("\nReversed List: ");
    printRevList(head);
    
    return 0;
}