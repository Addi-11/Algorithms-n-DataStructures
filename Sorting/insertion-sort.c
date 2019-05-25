#include<stdio.h>

void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void  insertionSort( int arr[], int n){

    for(int i = 0; i < n; i++){
        for(int j = i-1, di = i; arr[j] > arr[di] && j >= 0; j--, di--){
            //shift array
            swap(&arr[di], &arr[j]);
        }
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
    
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
