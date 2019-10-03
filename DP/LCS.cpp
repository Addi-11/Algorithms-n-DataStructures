#include<bits/stdc++.h>

int max(int a, int b){
    return (a>b)?a:b;
}

//STANDARD RECURSIVE APPROACH

/*int lcs(char *s1, char *s2, int m, int n){
    
    if(m == 0 || n == 0)
        return 0;
    if(s1[m-1] == s2[n-1]){
        std::cout << s1[m-1];
        return 1 + lcs(s1,s2,m-1,n-1);
    }
    else
    {
        return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
    
}*/

// TABULATED FORM

int lcs(char *s1, char *s2, int m, int n){

    int L[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(s1[i - 1] == s2[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[m][n];
}


int main(){
    char *s1, *s2;
    s1 = "abgtabs";
    s2 = "gxthjas";
    int m = strlen(s1);
    int n = strlen(s2);
    std::cout << lcs(s1, s2, m, n);
    return 0;
}