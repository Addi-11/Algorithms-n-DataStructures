#include<stdio.h>

int search(int start,int end,int arr[],int data){
    int mid = (end +start)/2;
    if(start <= end){
        if(arr[mid] == data){
            return mid;
        }
        if(arr[mid] > data){
            return search(start,mid-1,arr,data);
        } 
        //if(arr[mid] < data){
            return search(mid+1,end,arr,data);
        //} 
    }

    return -1;
}

int main(){
    int arr[] = {4,6,9,18,32,36,41,49,56,65,70,79,80,89,91,93,95,97,109};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n%d",n);
    int x = 62;
    int index = search(0,n,arr,x);
    if(index == -1)
        printf("\n%d not in array",x);
    else
        printf("\n%d in the array at index %d",arr[index],index);
    return 0;
}