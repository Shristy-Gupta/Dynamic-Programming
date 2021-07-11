#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	   int sum=0,finalsum=INT_MIN;
	   for(int i=0;i<S.length();i++){
	       if(S[i]=='1'){
	           sum+=-1;
	       }
	       else if(S[i]=='0'){
	           sum+=1;
	       }
	       if(finalsum<sum){
	           finalsum=sum;
	       }
	       if(sum<0){
	           sum=0;
	       }
	   }
	   return finalsum;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
