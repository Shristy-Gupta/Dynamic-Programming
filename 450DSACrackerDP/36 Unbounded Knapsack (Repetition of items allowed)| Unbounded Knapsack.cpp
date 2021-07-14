// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // Unbounded Knsapsack
        int dp[N+1][W+1];
        for(int i=0;i<=N;i++){
            //when weight of knapsack is 0 then profit is zero
            dp[i][0]=0;
        }
        for(int j=0;j<=W;j++){
            //When number of elements is zero then profit is 0
            dp[0][j]=0;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]>j){
                    //dont take that element
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    //Either take that element or dont take it
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
            }
        }
        return dp[N][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
