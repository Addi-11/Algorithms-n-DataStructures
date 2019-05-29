#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *nxt;
};

struct Node *top = NULL;



void push(int x){

    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    if(temp == NULL){
        temp->nxt = NULL;
    }
    temp->nxt = top;
    top = temp;
    
}

void pop(){
  top = top->nxt;
}

void Top(){
    if(top == NULL){
        printf("\nThe stack is empty");
        return;
    }
    printf("\n%d is the top",top->data);

}

void print(){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));   
    temp = top;
    printf("\nStack: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->nxt;
    }    
}

int main(){
    Top();
    push(34);
    push(10);
    Top();
    push(96);
    pop();
    Top();
    push(2);
    push(7);
    pop();
    Top();
    print();
    return 0;
}