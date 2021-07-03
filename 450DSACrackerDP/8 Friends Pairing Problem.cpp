#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    long long int M=1000000007;
    long long int countFriendsPairings(int* dp, int n){
        if(n<=2){return n;}
        if(dp[n]!=-1){return dp[n];}
        else{
            long long int left, right;
            if(dp[n-1]!=-1){left=dp[n-1];}
            else{
                left=countFriendsPairings(dp,n-1)%M;
                dp[n-1]=left;
            }
            if(dp[n-2]!=-1){right=dp[n-2];}
            else{
                right=countFriendsPairings(dp,n-2)%M;
                dp[n-2]=right;
            }
            return dp[n]=(left+((n-1)*right)%M)%M;
        }
        
    }
    int countFriendsPairings(int n) 
    { 
       if(n<=2){return n;}
       int* dp=new int[n+1];
       for(int i=0;i<=n;i++){
           dp[i]=-1;
       }
       return countFriendsPairings(dp, n); 
       
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
