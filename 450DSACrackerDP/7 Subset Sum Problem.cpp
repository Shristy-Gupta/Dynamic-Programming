// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
//https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7 
// 0-1 Knapsack
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){sum+=arr[i];}
        if(sum%2==1){
            return 0;
        }
        //Now apply 0-1 knapsack to calculate if sum = sum/2
        int K=sum/2;
        int dp[N+1][K+1];
        memset(dp,-1,sizeof(dp[0][0])*N+1*K+1);
        //Intialization
        for(int i=0;i<=K;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=N;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
                }
                
            }
            
        }
        
        if(dp[N][K]==K){
            return 1;
        }
        else{
            return 0;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
