#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    int knapsackhelper(int w, int wt[], int val[], int n, int** dp){
        if(w==0||n==0){
            return dp[n][w];
        }
        if(dp[n][w]!=-1){return dp[n][w];}
        int result;
        if(wt[n-1]>w){
           result=knapsackhelper(w,wt,val,n-1,dp); 
        }
        else{
            result=max(knapsackhelper(w,wt,val,n-1,dp),val[n-1]+knapsackhelper(w-wt[n-1],wt,val,n-1,dp));
        }
        return dp[n][w]=result;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // 0-1 knapsack
       int** dp=new int*[n+1];
       for(int i=0;i<=n;i++){
           dp[i]=new int[W+1];
           for(int j=0;j<=W;j++){
               //i==0 This means size of array is 0 and weight is non zero
               //j==0 This means 0 weight is present 
               if(i==0||j==0){
                   dp[i][j]=0;
               }
               else{
                   dp[i][j]=-1;
               }
           }
       }
       knapsackhelper(W,wt,val,n,dp);
       return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
