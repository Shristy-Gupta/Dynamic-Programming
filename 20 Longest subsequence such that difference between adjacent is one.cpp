// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#include <cstdlib>
class Solution{
public:
    
    int longestSubsequence(int N, int nums[])
    {
        int n=N;
        if(n<=1){return n;}
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        int ans=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(nums[j]-nums[i])==1){
                    //consider the element
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
