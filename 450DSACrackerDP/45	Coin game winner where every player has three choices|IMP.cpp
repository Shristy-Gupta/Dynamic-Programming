// In each move a player can pick x or y or 1 coins
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool findWinner(int x, int y, int n)
{
   bool dp[n+1];
   dp[0]=false;
   dp[1]=true;
   for(int i=2;i<=n;i++){
       if(i-1>=0 && !dp[i-1])
       dp[i]=true;
       else if(i-x>=0 && !dp[i-x])
       dp[i-x]=true;
       else if(i-y>=0 && !dp[i-y])
       dp[i-y]=true;
       else
       dp[i]=false;
   }
    return dp[n];
}

// Driver program to test findWinner();
int main()
{
    int x = 2, y = 3, n = 4;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';
 
    return 0;
}
