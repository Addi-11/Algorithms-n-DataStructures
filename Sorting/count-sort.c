#include<stdio.h>
#include<string.h>

#define Range  255

void countSort( int arr[], int n){

    int count[Range];
    int output[n];

    //initialise the array to 0
    memset(count, 0, sizeof(count));

    //count the repitition of an element in array
    for(int i = 0; i < Range; i++){
        for(int j = 0; j < n; j++){
            if( i == arr[j])
               count[i]++;
        }
    }

    //sumation of no. of repititions

    for(int i = 1; i < Range; i++){
        count[i] += count[i-1];
    } 

    //output each array element at one less position specified by the count

    for(int i = 0; i < Range; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] == i){
                output[count[i]-1] = arr[j];
                count[i] = (count[i]-1);
            }
        }
    }

    print(output,n);
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
    
    countSort(arr, n);
    //print(arr, n);
    return 0;
}