#include<stdio.h>
#include<stdbool.h>

#define max 20

int front = -1, rear = -1;
int queue[max];

bool IsEmpty(){
    if(front == -1 && rear == -1)
    {
        printf("Queue Empty");
        return true;
    }
    else
    {
        printf("Queue not empty");
        return false;
    }
}

void Enqueue(int x){
    if((rear + 1)%max == front){
        printf("Queue full");
        return;
    } else if(IsEmpty()){
        front = 0;
        rear = 0;
    } else{
        rear = (rear+1)%max;//circular array
    }
    queue[rear] = x;
}

void Dequeue(){
    if( IsEmpty()){
        return;
    } else if(rear == front){
        rear = -1;
        front = -1;
    } else{
        front = (front+1)%max;
    }
}

int main(){
    IsEmpty();
    Enqueue(5);
    Dequeue();
    Enqueue(6);
    Enqueue(7);
    Enqueue(9);
    Front();
    return 0;
}