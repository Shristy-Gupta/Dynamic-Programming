// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //https://www.youtube.com/watch?v=oDhu5uGq_ic
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N+1];
        int ans=0;
        for(int i=0;i<=K;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=N;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=K;i++){
            int maxdiff=INT_MIN;
            for(int j=1;j<N;j++){
                    //Assuming we can buy or sell the stock on same day
                    maxdiff=max(maxdiff,dp[i-1][j-1]-A[j-1]);
                    dp[i][j]=max(maxdiff+A[j],dp[i][j-1]);
                //     dp[i][j]=INT_MIN;
                //     for(int m=0;m<j;m++)
                //   { 
                //     dp[i][j]=max(dp[i][j],(A[j]-A[m])+dp[i-1][m]);
                    
                //   }
                //   dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
