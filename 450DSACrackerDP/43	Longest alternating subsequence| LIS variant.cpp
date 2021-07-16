#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    public:
    int dp[100001][2];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
		int AlternatingaMaxLength(vector<int>&a){
		    //LIS variant
		    int n=a.size();
		    if(n<=1){return n;}
		    for(int i=0;i<n;i++){
		        dp[i][0]=1;
		        dp[i][1]=1;
		    }
		    int ma=0;
		    for(int i=1;i<n;i++){
		        for(int j=0;j<i;j++){
		            if(a[i]>a[j]){
		                dp[i][0]=max(dp[i][0],dp[j][1]+1);
		            }
		            else if(a[i]<a[j]){
		                dp[i][1]=max(dp[i][1],dp[j][0]+1);
		            }
		            ma=max(ma,max(dp[i][0],dp[i][1]));
		        }
		    }
		    return ma;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends



///////////////////// optimized
int AlternatingaMaxLength(vector<int>&nums){
            int n=nums.size();
            int ma=1;
            int mi=1;
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1]){
                    ma=mi+1;
                }
                else if(nums[i]<nums[i-1]){
                    mi=ma+1;
                }
                else{
                    continue;
                }
            }
            return max(ma,mi);
		}
