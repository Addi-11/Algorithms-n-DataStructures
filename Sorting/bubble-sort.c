#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;  
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



    for( j = 0; j < n-1; j++){
        for (i = 0; i < n-j-1; i++){
                if(arr[i] > arr[i+1]){
                    swap(&arr[i], &arr[i+1]);
                }
            }
    }
    
    //print the sorted array
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}