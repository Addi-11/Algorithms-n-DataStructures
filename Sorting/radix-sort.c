#include<stdio.h>
#include<string.h>
#include<math.h>

int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > mx)
           mx = arr[i];
    }
    return mx;
}


void countSort(int arr[], int n, int exp){

    int output[n];
    int count[10] = {0}; ///single digits are sorted each at a time

    //countSort usual


    for (int i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++;
    
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }


     for (int i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    }
    
   //copy output into array
   for(int i = 0; i < n; i++){
       arr[i] = output[i];
   }
    
    print(arr, n);

}

void radixSort(int arr[], int n){
   //sort everything acc. to their one's place then ten's place and so on...counting sort used intermediatry.

   int max = getMax(arr, n);

   for(int exp = 1; max/exp > 0 ; exp *= 10){
       countSort(arr, n, exp);
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
    
    radixSort(arr, n);

    print(arr, n);
    return 0;
}