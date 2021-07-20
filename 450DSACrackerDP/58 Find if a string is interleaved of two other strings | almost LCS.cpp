//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  unordered_map<string,bool>mem;
   bool check(string s1, string s2, string s3,int n1, int n2, int n3, int p1, int p2, int p3){
       if(p3==n3){
           return (p1==n1 && p2==n2)?true:false;
       }
       string key=to_string(p1)+"_"+to_string(p2)+"_"+to_string(p3);
       if(mem.find(key)!=mem.end())
       return mem[key];
       if(p1==n1){
           return mem[key]=s2[p2]==s3[p3]?check(s1,s2,s3,n1,n2,n3,p1,p2+1,p3+1):false;
       }
       else if(p2==n2){
            return mem[key]=s1[p1]==s3[p3]?check(s1,s2,s3,n1,n2,n3,p1+1,p2,p3+1):false;
       }
       bool one=false ,two=false;
       if(s1[p1]==s3[p3]){
           one=check(s1,s2,s3,n1,n2,n3,p1+1,p2,p3+1);
       }
       if(s2[p2]==s3[p3]){
           two=check(s1,s2,s3,n1,n2,n3,p1,p2+1,p3+1);
       }
       return mem[key]=one or two;
   }
    
    bool isInterleave(string A, string B, string C) 
    {
        //https://www.youtube.com/watch?v=EzQ_YEmR598
        int n1=A.length();
        int n2=B.length();
        int n3=C.length();
        if(n3!=n1+n2){
            return false;
        }
        //Last 3 are pointers P1,P2,and P3
        mem.clear();
        return check(A,B,C,n1,n2,n3,0,0,0);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
