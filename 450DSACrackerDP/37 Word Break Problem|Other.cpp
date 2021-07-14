//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    int n=A.length();
    int dictlen=B.size();
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<dictlen;j++){
            if(dp[i]==1){break;}
            if(i+B[j].length()<=n && A.substr(i,B[j].length())==B[j]){
                dp[i]=dp[i+B[j].length()];
            }
        }
    }
    return dp[0];
}
