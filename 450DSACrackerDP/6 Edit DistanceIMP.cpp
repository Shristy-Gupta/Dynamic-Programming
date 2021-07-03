#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  //Convert one string to another string
  //https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25
    int editDistance(string s, string t) {
        //Identification of the problem 
        //Given a string convert it to another string in MIN operations
        //we have three operations either to insert, remove or replace the element-->longest subsequence matching
        if(s.compare(t)==0){
            return 0;
        }
        if(s.length()==0 && t.length()!=0){
            return t.length();
        }
        if(s.length()!=0 && t.length()==0){
            return s.length();
        }
        if(s.length()==0 && t.length()==0){
            return 0;
        }
        int n=s.length(),m=t.length();
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp[0][0])*n+1*m+1);
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(s[i-1]==t[j-1]){//imp
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //delelte, insert, replace
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        
       return dp[n][m]; 
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
