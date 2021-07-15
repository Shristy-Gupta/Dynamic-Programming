//0-1 Knapsack
//Optimized and original code


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
  //https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7 
// 0-1 Knapsack
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){sum+=arr[i];}
        if(sum%2==1){
            return 0;
        }
        //Now apply 0-1 knapsack to calculate if sum = sum/2
        int K=sum/2;
        int dp[N+1][K+1];
        //Intialization
        for(int j=0;j<=K;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                
            }
            
        }
        
        return dp[N][K];
    }
};
  //Optimized
    int equalPartition(int n, int arr[])
    {
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1];
 
    // Initialize the part array
    // as 0
    for (i = 0; i <= sum / 2; i++) {
        part[i] = 0;
    }
 
    // Fill the partition table in bottom up manner
 
    for (i = 0; i < n; i++) {
        // the element to be included
        // in the sum cannot be
        // greater than the sum
        for (j = sum / 2; j >= arr[i];
             j--) { // check if sum - arr[i]
            // could be formed
            // from a subset
            // using elements
            // before index i
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }
 
    return part[sum / 2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
