#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
#include<vector>
class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
    	  vector<int> val, wt;
    
        // traverse the original cost[] array and skip
        // unavailable packets and make val[] and wt[]
        // array. size variable tells the available number
        // of distinct weighted packets
        int size = 0;
        for (int i=0; i<N; i++)
        {
            if (cost[i]!= -1)
            {
                val.push_back(cost[i]);
                wt.push_back(i+1);
                size++;
            }
        }
     
        N = size;
    
        // 0-1 Knapsack
       long long int dp[N+1][W+1];
        //Intialize
        //when no of elements is 0 then dp[0][j]=INT_MAX
        for(int j=0;j<=W;j++){
            dp[0][j]=INT_MAX;
        }
        //When weight is 0 then the dp[i][0]=0;
        for(int i=1;i<=N;i++){
            dp[i][0]=0;
        }
    
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=min(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
               
            }
          
        }
        if(dp[N][W]==INT_MAX){return -1;}
        return dp[N][W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
