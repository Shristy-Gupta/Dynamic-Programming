using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod;
  int dp[1000];
  Solution(){
      mod=1000000007;
      memset(dp,-1,sizeof(dp));
  }
    long long int countBT(int h) { 
        if(h<=1){return 1;}
        if(dp[h]!=-1){return dp[h];}
        long long int a=countBT(h-1);
        long long int b=countBT(h-2);
        dp[h]=(a*((2*b)%mod+a)%mod)%mod;
        return dp[h];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends
