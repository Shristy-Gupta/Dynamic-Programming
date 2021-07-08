// https://www.geeksforgeeks.org/space-optimized-solution-lcs/
//O(n) time complexity
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int lcs(string &X, string &Y)
{
    /*One important observation in the above simple implementation is, in each iteration of the outer loop we only need values from all columns of the previous row. So there is no need to store all rows in our DP matrix, we can just store two rows at a time and use them*/
    int m=X.length(),n=Y.length();
    int L[2][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            int a=i%2;
            if(i==0||j==0){
                L[a][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                L[a][j]=1+L[1-a][j-1];
            }
            else{
                L[a][j]=max(L[1-a][j],L[a][j-1]);
            }
            cout<<L[a][j]<<" ";
        }
        cout<<endl;
    }
    if(m%2==1)
    return L[0][n];
    else{
        return L[1][n];
    }
}
int main() {
     string X = "AGGTAB";
    string Y = "GXTXAYB";
 
    printf("Length of LCS is %d\n", lcs(X, Y));
 
    return 0;
}
