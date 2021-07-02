// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
//https://github.com/Shristy-Gupta/Dynamic-Programming/blob/main/Topics/Matrix%20Chain%20Multiplication
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int MatrixChainOrder(int p[], int i, int j){
    //Scheme
    //for(k=i to j-1) and partition is from i to k and k+1 to j
    int ans=INT_MAX,tempans;
    if(i>=j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    for(int k=i;k<j;k++){
    tempans=MatrixChainOrder(p,i,k)+MatrixChainOrder(p,k+1,j)+p[i-1]*p[k]*p[j];
    ans=min(ans,tempans);
    }
    return dp[i][j]=ans;
}
int MatrixChainOrder_secondVariant(int p[], int i, int j){
    //Scheme
    //for(k=i to j) and partition is from i to k-1 and k to j
    int ans=INT_MAX,tempans;
    if(i>=j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    for(int k=i+1;k<=j;k++){
    tempans=MatrixChainOrder(p,i,k-1)+MatrixChainOrder(p,k,j)+p[i-1]*p[k-1]*p[j];
    ans=min(ans,tempans);
    }
    return dp[i][j]=ans;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp,-1,sizeof(dp[0][0])*1000*1000);
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);

    return 0;
}
