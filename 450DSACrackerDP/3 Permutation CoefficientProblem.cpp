// https://www.geeksforgeeks.org/permutation-coefficient/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int permutationcoeffiecient(int n, int k){
    
    
    if(k>n){return  0;}
    if(k==0){return 1;}
    return permutationcoeffiecient(n-1,k) + k*permutationcoeffiecient(n-1,k-1);
}
int main() {
    int n=4,k=2;
    memset(dp,0,sizeof(dp[0][0])*1000*1000);
    //Intialization
    //if k>n then its invalid, also 
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j>i || j>k){break;}
            dp[i][j]=dp[i-1][j]+j*dp[i-1][j-1];
        }
    }
    cout<<dp[n][k]<<endl;
    cout<<permutationcoeffiecient(n,k);

    return 0;
}
