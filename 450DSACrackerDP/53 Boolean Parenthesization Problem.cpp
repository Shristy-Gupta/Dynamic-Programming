// Initial Template for C++
// There is some issue
// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    //https://www.youtube.com/watch?v=pGVguAcWX4g
public:
 unordered_map<string, int> umap;
    int solve(string S, int i, int j, bool isSolve){
        //MCM
        if(i>j){
            return 1;
        }
        if(i==j){
            if(isSolve){
                return S[i]=='T';
            }
            else{
                return S[i]=='F';
            }
        }
        string key=to_string(i);
        key.push_back('_');
        key.append(to_string(j));
        key.push_back('_');
        key.append(to_string(isSolve));
        if(umap.find(key)!=umap.end()){
            return umap[key];
        }
        //cout<<key<<endl;
        int ans=0;
        for(int k=i+1;k<=j-1;k=k+2){
            int lt,lf,rt,rf;
            lt=solve(S,i,k-1,true);
            lf=solve(S,i,k-1,false);
            rt=solve(S,k+1,j,true);
            rf=solve(S,k+1,j,false);
         
            if(S[k]=='&'){
                if(isSolve){
                    ans+=lt*rt;
                }
                else{
                    ans+=(lf*rt)+(lt*rf)+(lf*rf);
                }
            }
            else if(S[k]=='|'){
                if(isSolve){
                    ans+=(lf*rt)+(lt*rf)+(lt*rt);
                }
                else{
                    ans+=lf*rf;
                }
            }
            else if(S[k]=='^'){
                if(isSolve){
                    ans+=(lf*rt)+(lt*rf);
                }
                else{
                    ans+=(lf*rf)+(lt*rt);
                }
            }
            
        }
        umap[key]=ans;
        return ans;
        
    }
    int countWays(int N, string S){
        if(N<=0){return 0;}
        umap.clear();
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
