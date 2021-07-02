// https://www.geeksforgeeks.org/program-nth-catalan-number/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
unsigned long long int dp[1000];
int catalan(int i){
   if(i<=1){return 1;}
 
   if(dp[i]!=-1){return dp[i];}
   unsigned long long int ans=0;
   for(int k=0;k<i;k++){
       //left ans
       int left,right;
       if(dp[k]!=-1){left=dp[k];}
       else{left=catalan(k);dp[k]=left;}
       if(dp[i-k-1]!=-1){right=dp[i-k-1];}
       else{right=catalan(i-k-1);dp[i-k-1]=right;}
       ans+=left*right;
   }
   return dp[i]=ans;
    
}
int main() {
    // C0 =1and Cn+1=Sum of CiCn-i for n>=0
    memset(dp,-1,sizeof(dp));
   
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";

    return 0;
}
