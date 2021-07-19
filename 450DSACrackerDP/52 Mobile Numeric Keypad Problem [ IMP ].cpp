#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		long long dp[N+1][10];
		memset(dp,0,sizeof(dp));
		vector<int> allowed[10];
		allowed[0]={0,8};
		allowed[1]={1,2,4};
		allowed[2]={1,2,3,5};
		allowed[3]={2,3,6};
		allowed[4]={1,4,5,7};
		allowed[5]={2,4,5,6,8};
		allowed[6]={3,5,6,9};
		allowed[7]={4,7,8};
		allowed[8]={5,7,8,9,0};
		allowed[9]={6,8,9};
		for(int i=1;i<=N;i++){
		    for(int j=0;j<=9;j++){
		        if(i==1){
		            dp[i][j]=1;
		        }
		        else{
		            for(int k=0;k<allowed[j].size();k++){
		               dp[i][j]+=dp[i-1][allowed[j][k]]; 
		            }
		        }
		    }
		}
		
		long long ans=0;
		for(int j=0;j<=9;j++){
		    ans+=dp[N][j];
		}
		return ans;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
