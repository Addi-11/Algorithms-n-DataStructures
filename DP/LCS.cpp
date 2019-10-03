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

// MEMOISED FORM
const int maximum = 1000;

int LCS(char *s1, char *s2, int m, int n, int l[][maximum]){
    
    
    if(m == 0 || n == 0){
        return 0;
        }
    if(l[m-1][n-1] != -1){
        return l[m-1][n-1];
    }
    if(s1[m-1] == s2[n-1]){
        l[m-1][n-1] = 1 + LCS(s1,s2,m-1,n-1, l);
        return l[m-1][n-1];
    }
    else
    {
        l[m-1][n-1] = max(LCS(s1,s2,m-1,n, l),LCS(s1,s2,m,n-1,l));
        return l[m-1][n-1];
    }
    
}

int main(){
    char *s1, *s2;
    s1 = "abgtabs";
    s2 = "gxthjas";
    int m = strlen(s1);
    int n = strlen(s2);

    int l[m][maximum];
    memset(l,-1,sizeof(l));
    
    // tabulated output
    std::cout << lcs(s1, s2, m, n);
    // memoized output
    std::cout << LCS(s1, s2, m, n, l);
    return 0;
}