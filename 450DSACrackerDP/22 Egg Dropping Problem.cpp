#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        if (k == 1 || k == 0)
		return k;

	    // We need k trials for one
	    // egg and k floors
	    if (n == 1)
		    return k;
       
       if(dp[n][k]!=-1){return dp[n][k];}
        // The idea is we either use that egg or not use that egg
        int min = INT_MAX, x, res;

    	// Consider all droppings from
    	// 1st floor to kth floor and
    	// return the minimum of these
    	// values plus 1.
    	for (x = 1; x <= k; x++) {
    		res = max(
    			eggDrop(n - 1, x - 1),
    			eggDrop(n, k - x));
    		if (res < min)
    			min = res;
    	}
        
        return dp[n][k]=min+1;
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
