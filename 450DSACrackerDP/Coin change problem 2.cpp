class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //Unbounded Knapsack
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=amount;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int j=0;j<=n;j++){
            dp[j][0]=0;
        }
        for(int i=1;i<=amount;i++){
            if(coins[0]%i==0){
                dp[1][i]=i/coins[0];
            }
            else{
            dp[1][i]=INT_MAX-1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    //Take it
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]==INT_MAX-1){return -1;}
        return dp[n][amount];
        
    }
};
