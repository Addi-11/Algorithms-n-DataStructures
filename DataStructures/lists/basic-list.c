#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head ;

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

    //free(temp);..no idea why it isnt working
}

int main(){
    char ans;
    int x, n;
    head = NULL;

    printf("\nHow many no.'s?");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the number:");
        scanf("%d",&x);
        insert(x);
        printList();
    }
    
    return 0;
    //printf("\nWanna create a list?? (y/n)");
    //scanf("%c", &ans);

    /*if(ans == 'y'){
        printf("\nEnter the list entity: ");
        scanf("%d", &x);
        insert(x);
        printList();
        }
    else 
        return 0;*/
    
}