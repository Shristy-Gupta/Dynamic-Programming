//https://practice.geeksforgeeks.org/problems/coin-change2448/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int coinhelper(int coins[], long long int** dp, int n, int k){
       if(n==0||k==0){return dp[n][k];}
       if(dp[n][k]!=-1){return dp[n][k];}
       long long int finalans=0;
       if(coins[n-1]>k){
           finalans=coinhelper(coins,dp,n-1,k);
       }
       else{
           finalans=coinhelper(coins,dp,n-1,k)+coinhelper(coins,dp,n,k-coins[n-1]);
       } 
       return dp[n][k]=finalans; 
       
    }
    long long int count( int S[], int n, int k)
    {
       

      long long int** dp=new long long int*[n+1]; 
      //initailize
      for(int i=0;i<=n;i++){
          dp[i]=new long long int[k+1];
          for(int j=0;j<=k;j++){
              if(i==0){
                  dp[i][j]=0;
              }
              else if(j==0){
                  dp[i][j]=1;
              }
              else{
                  dp[i][j]=-1;
              }
          }
      }
        
       dp[0][0]=1; 
      coinhelper(S,dp,n,k);
      /*
      for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        } 
        */
      return dp[n][k];  
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
