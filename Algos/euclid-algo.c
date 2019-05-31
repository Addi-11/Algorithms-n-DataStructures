//calculate HCF
#include<stdio.h>

int hcf(int a, int b){
    int num1,num2;
    if(a > b){
        num1 = a;
        num2 = b;
    } else{
        num1 = b;
        num2 = a;
    }

    int rem, divisor, dividend;
    dividend = num1;
    divisor = num2;
    rem = dividend%divisor;
    while(rem >= 0 ){
       rem = dividend%divisor;
       if(rem == 0)
           break;
       dividend = divisor;
       divisor = rem;

    }

    return divisor;
}

int main(){
    printf("%d %d",hcf(78,464),hcf(117,1512));
    return 0;
}