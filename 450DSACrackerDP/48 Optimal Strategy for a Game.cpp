#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    //learn gap method
    long long dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=i,k=0;j<n;j++,k++){
            if(i==0){
                //gap is zero
                dp[k][j]=arr[k];
            }
            else if(i==1){
                //gap is 1
                dp[k][j]=max(arr[k],arr[j]);
            }
            else{
                long long val1=arr[k]+min(dp[k+1][j-1],dp[k+2][j]);
                long long val2=arr[j]+min(dp[k+1][j-1],dp[k][j-2]);
                dp[k][j]=max(val1,val2);
            }
        }
    }
    return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
