#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        //Top down
        int len1=S1.length(),len2=S2.length();
        int dp[len1+1][len2+1];
        //intialization
        for(int j=0;j<=len2;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=len1;i++){
            dp[i][0]=0;
        }
        int ans=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
