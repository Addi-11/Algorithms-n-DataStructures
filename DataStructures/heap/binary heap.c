#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}

void max_heapify(int arr[],int n, int i){
   int max = i;
   int l = 2*i, r = 2*i + 1;
   if(l < n && arr[l] > arr[max])
       max = l;//left child
    if(r < n && arr[r] > arr[max])
       max = r;//right child
    if(i != max){
       swap(&arr[i], &arr[max]);
       max_heapify(arr,n, max);
    }
       
}

void buildHeap(int arr[], int n){

    for(int i = n/2; i >= 0; i--){
        max_heapify(arr,n,i);
    }
}

void print(int arr[], int n){
    printf("\n");
    for(int i = 0; i < n; i ++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int i;
    int arr[] = {0,4,12,21,78,46,33,15,37,20,45,200,14,75,130,29,89,31,154};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    buildHeap(arr, n);

    print(arr, n);
    return 0;
}