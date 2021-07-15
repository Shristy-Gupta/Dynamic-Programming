//https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Driver program to test above functions */
int lps(char *seq, int i, int j,int n){
    if(n<=1){
        return n;
    }
    int dp[n+1][n+1];
    //intialization
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dp[0][i]=0;
        dp[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(seq[i-1]==seq[n-1-j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][n];
    
}
int main()
{
    char seq[] = "shristygupta";
    int n = strlen(seq);
    cout << "The length of the LPS is "
         << lps(seq, 0, n-1,n);
    return 0;
}
