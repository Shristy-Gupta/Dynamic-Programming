1) Subset Sum Problem https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7 
https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
if(arr[i-1]<=j){ dp[i][j]=dp[i-1][j-arr[i-1]|| dp[i-1][j];} else{dp[i][j]=dp[i-1][j];}
2) Equal Sum Partition Problem: https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8
https://www.geeksforgeeks.org/partition-problem-dp-18/
3) Count of subset Sum: https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9
if(arr[i-1]<=j){ dp[i][j]=dp[i][j-arr[i-1]+ dp[i-1][j];} else{dp[i][j]=dp[i-1][j];}
4) Minimum Subset Sum Difference: https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

void knapsack(vector<int>& A,vector<vector<bool>>&dp, int n, int sum){
    if(n<=0 || sum<=0){
        return;
    }
    for(int i=0;i<=n;i++){
        //If there is no knapsack weight we say it can be filled
        dp[i][0]=1;
    }
    for(int j=0;j<=sum;j++){
        //if there is no value  available we cant fill the bag
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=A[i-1]){
                //we either take the value or not take the value
                dp[i][j]=dp[i-1][j-A[i-1]] || dp[i-1][j];
            }
            else{
                //here we cant take the value
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
}
int Solution::solve(vector<int> &A) {
    int n=A.size();
    int total_sum=0;
    if(n<=0){
        return 0;
    }
    if(n==1){
        return A[0];
    }
    for(int i=0;i<n;i++){
       total_sum+=A[i]; 
    }
    //variant of 0-1 knapsack
    //Here we will find knapsack for n numbers and total_sum/2 because maximun difference will be 
    //total_sum/2
    vector<vector<bool>> dp= vector<vector<bool>>(n+2,vector<bool>(total_sum/2+1,0));
    knapsack(A,dp,n,total_sum/2);
    int min_ans=INT_MAX;
    for(int j=1;j<=total_sum/2;j++){
       if(dp[n][j])
        min_ans=min(min_ans,abs(total_sum-2*j));
    }
    return min_ans;
}

5) Target Sum: https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12
6) Number of Subset with given difference: https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11


