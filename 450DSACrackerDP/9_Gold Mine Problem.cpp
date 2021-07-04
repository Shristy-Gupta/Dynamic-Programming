// Gold Mine Problem
//He can move only (right->,right up /,right down\)
//Graph Dynamic Programming
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int goldTable[MAX][MAX];
int getMaxGold(int gold[][MAX], int m, int n, int i, int j){
    if(i<0 ||j<0 ||j>=n || i>=m){
        return 0;
    }
    else if(goldTable[i][j]!=-1){
            return goldTable[i][j];
        }
    else{
        
        int left=0,downleft=0,upright=0;
        if(j-1>=0){
            if(goldTable[i][j-1]!=-1){
                left=goldTable[i][j-1];
            }
            else{
                left=getMaxGold(gold,m,n,i,j-1);
                goldTable[i][j-1]=left;
            }
            
            if(i+1<m){
                   if(goldTable[i+1][j-1]!=-1){
                    downleft=goldTable[i+1][j-1];
                    }
                else{
                    downleft=getMaxGold(gold,m,n,i+1,j-1);
                    goldTable[i+1][j-1]=downleft;
                } 
            }
            if(i-1>0){
                   if(goldTable[i-1][j-1]!=-1){
                    upright=goldTable[i-1][j-1];
                    }
                else{
                    upright=getMaxGold(gold,m,n,i-1,j-1);
                    goldTable[i-1][j-1]=upright;
                } 
            }
        }
        return goldTable[i][j]=gold[i][j]+ max(left,max(upright,downleft));
    }
    
    
}

int main() {
    memset(goldTable, -1, sizeof(goldTable));
     int gold[MAX][MAX]= {{1, 3, 3},
                         {2, 1, 4},
                         {0, 6, 4}};
    int m = 3, n = 3;
    int ans=INT_MIN;
    //Fill the first column of the matrix goldTable
    for(int i=0;i<m;i++){
        goldTable[i][0]=gold[i][0];
    }
    for(int i=m-1;i>=0;i--){
             getMaxGold(gold, m, n,i,n-1);
             ans=max(ans,goldTable[i][n-1]);
        }
 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<goldTable[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;

    
}
