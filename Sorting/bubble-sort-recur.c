#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}

void bubbleSort(int arr[], int n){


    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
        }
    }

    if(n-1 > 1){
        bubbleSort(arr, n-1);
    } 
    else return;
    
}

int main(){
    int i,j, n;
    int arr[n];

    //input
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    
    //print the sorted array
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}