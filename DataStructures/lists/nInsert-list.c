#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void printList(){
    struct Node *temp = head;

    printf("\nThe list is : ");
    while(temp != NULL){
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


int nInsert(int value, int pos){
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));

   temp1->data = value;
   temp1->next = NULL;

   //special case for pos = 1
   if(pos == 1){
       temp1->next = head;
       head = temp1;
   }
   else{
        //traversal of list to the required point
        temp = head;
        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        temp1 ->next = temp->next;
        temp->next = temp1;
   }
}

int main(){
    char ans;
    int x, n;
    head = NULL;

    //create a list
    printf("\nHow many no.'s?");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the number:");
        scanf("%d",&x);
        insert(x);
    }

    printList();

    //Inserts at nth postion
    nInsert(2,3); //data,position
    nInsert(5,3);
    nInsert(3,2);
    nInsert(16,1);
    nInsert(23,4);

    printList();
    
    return 0;
}