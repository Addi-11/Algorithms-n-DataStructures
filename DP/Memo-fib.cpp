// Memiozated version
#include<bits/stdc++.h>

#define MAX 100
#define NIL -1

int lookup[MAX];

// initialise lookup table
void _initialise(){
    for(int i = 0; i < MAX; i++){
        lookup[i] = NIL;
    }
}

int fib(int n){

    if( lookup[n] == NIL){ 
        if(n <=1)
            lookup[n] = n;
        else
            lookup[n] = fib(n-1) + fib(n-2);
    }   
    return lookup[n];
}

int main(){
    _initialise();
    // 0 1 1 2 3 5 8 13 21 34 55
    int n = 6;
    std::cout << fib(n);
    return 0;
}