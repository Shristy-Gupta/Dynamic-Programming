// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    long int dp[100000];
  
    Solution(){
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
    }
    long int disarrange(int N){
          long int mod=1000000007;
        if(N<=1){
            return 0;
        }
        if(N==2){
            return 1;
        }
        if(dp[N]!=-1){return dp[N];}
        return dp[N]=((N-1)*(disarrange(N-1)+disarrange(N-2))%mod)%mod;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
