#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
       int dp[n+1][m+1]={0};
       for(int i=0;i<=n;i++){
           dp[i][0]=0;
       }
       for(int j=0;j<=m;j++){
           dp[0][j]=0;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }
               else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       return dp[n][m];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
