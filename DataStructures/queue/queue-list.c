//all operations in O(1) time

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* nxt;
};

//Queue moves toward right front-->rear
struct Node* front ;
struct Node* rear ;

void Enqueue(int x){
    //addition at  the rear end
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x; 
    temp->nxt = NULL;

    if(front == NULL && rear == NULL){
        front = temp;
        rear = temp;
        return;
    }
    rear->nxt = temp;
    rear = temp;

}

void Dequeue(){
    //remove element from front
    if(front == NULL){
        printf("Queue is empty");
        return;
    }
    if(front == rear){
        //resetting parameters on dequeue of 1st element..ie back to empty queue
        front = NULL;
        rear = NULL;
    }  else
        front = front->nxt;
}

void print(){
    
    struct Node* temp = front;
    //traversal of queue from the end
    printf("\n");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->nxt;
    }
}

void IsEmpty(){
    if(front == NULL){
        printf("\nQueue is Empty");
    } else{
        printf("\nQueue is not empty");
    }
}

int main(){
    rear = NULL;
    front = NULL;
    IsEmpty();
    Enqueue(5);
    Dequeue();
    Enqueue(6);
    Enqueue(7);
    Enqueue(9);
    Enqueue(45);
    Dequeue();
    Enqueue(26);
    Enqueue(70);
    Enqueue(19);
    print();
}