class Solution {
public:
    int robhelper(vector<int>& nums, int x){
        //recursion
        int n=nums.size();
        if(x<0 ||x>=n){
            return 0;
        }
        //either take the element at x or leave it!
        return max(nums[x]+robhelper(nums,x+2),robhelper(nums,x+1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=0){
            return 0;
        }
        int dp[n+1];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
       //return robhelper(nums,0);
        
    }
};
