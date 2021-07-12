// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int dp[MAX][MAX];

int countremovals(int arr[],int start,int end,int k){
    if(start>end){
        return 0;
    }
    else if(arr[end]-arr[start]<=k){return 0;}
    else{
        if(dp[start][end]!=-1){return dp[start][end];}
        //greater than 0
        dp[start][end]=1+min(countremovals(arr,start+1,end,k),
        countremovals(arr,start,end-1,k));
        return dp[start][end];
        
    }
} 
int  removals(int arr[],int n,int k){
    sort(arr,arr+n);
    memset(dp,-1,sizeof(dp[0][0])*100*100);
    if(n==1){
        if(arr[0]>k){return 1;}
        else{return 0;}
    }
    return countremovals(arr,0,n-1,k);
}
int main()
{
    int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
    int n = 9;
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
