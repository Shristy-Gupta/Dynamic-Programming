// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unsigned long long nCr(int n, int k){
        const unsigned int M = 1000000007;
        if(n<k){return 0;}
        if(n==k){return 1;}
         unsigned long long C[k + 1];
        memset(C, 0, sizeof(C));
 
        C[0] = 1; // nC0 is 1
 
         for (int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j - 1])%M;
       }
       return C[k];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
