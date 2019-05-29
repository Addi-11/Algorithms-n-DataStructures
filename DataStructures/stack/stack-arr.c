#include<stdio.h>

#define MAX_SIZE 20

int arr[MAX_SIZE];
int top = -1;

void push(int x){
    if( top > MAX_SIZE-1){
        printf("\nStack-Overflow");
        return;
    }
    arr[++top] = x;
}

void pop(){
    if(top == -1){
        printf("\nError:no element in the top.");
        return;
    }
   --top;
}

void Top(){
   printf("\nThe top is : %d",arr[top]);
}

void print(int arr[]){
    printf("\nStack: ");
    for(int i = 0; i<=top; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
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
    print(arr);
    return 0;
}