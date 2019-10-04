#include<iostream>

#define MAX 100000

int ugly[MAX];

void _initialise(){
    for(int i = 0; i < MAX; i++){
        ugly[i] = 0;
    }
    ugly[0] = 1;
    ugly[1] = 1;
}

int chkUgly(int n){
    if(ugly[n] == 1){
        return 1;
    }
    else{
        if( n%2 == 0)
            return chkUgly(n/2);
        else if( n%3 == 0)
            return chkUgly(n/3);
        else if( n%5 == 0)
            return chkUgly(n/5);
        else return 0;
    }
}

int getUgly(int n){
    int i = 1, count = 1;
    while(count <= n){
        if(chkUgly(i) == 1){
            count++;
        }
        i++;
    }
    return i-1;
}

int main(){
    _initialise();
    std::cout << getUgly(1);
    return 0;
}