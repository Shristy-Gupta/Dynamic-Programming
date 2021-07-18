// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int palindrome(string str, int start, int end){
        if(start>end){
            return false;
        }
        while(start<=end){
            if(str[start++]!=str[end--]){
                return false;
            }
        }
        return true;
    }
    int palindromicPartitionHelper(string str, int start, int end){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=-1){return dp[start][end];}
        if(palindrome(str,start,end)){return 0;}
        int ans=INT_MAX;
        for(int k=start;k<end;k++){
            //memoize
            int part1,part2;
            if(dp[start][k]!=-1){
                part1=dp[start][k];
            }
            else{
                part1=palindromicPartitionHelper(str,start,k);
                dp[start][k]=part1;
            }
            if(dp[k+1][end]!=-1){
                part2=dp[k+1][end];
            }
            else{
                part2=palindromicPartitionHelper(str,k+1,end);
                dp[k+1][end]=part2;
            }
            int tempans=part1+part2;
            ans=min(ans,1+tempans);
        }
        return dp[start][end]=ans;
    }
    int palindromicPartition(string str)
    {
        // Matrix chain multiplication variant
        if(str.length()<=1){
            return str.length();
        }
        return palindromicPartitionHelper(str,0,str.length()-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
