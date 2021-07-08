#include <bits/stdc++.h>
# include<vector>  
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp;
	    int sum=0;
	    for(int i=0;i<n;i++){dp.push_back(arr[i]);}
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	            }
	        }
	    }
	    
	    int p=dp.size();
	    for(int i=0;i<p;i++){
	        sum=max(sum,dp[i]);
	    }
	    return sum;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
