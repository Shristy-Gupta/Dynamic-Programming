class Solution {
//LIS Variant
     static bool compareInterval(vector<int> pair1, vector<int> pair2){
        return pair1[0]<pair2[0];
    }
    public:
   
    int findLongestChain(vector<vector<int>>& pairs) {
        int maxsofar=INT_MIN;
        int n=pairs.size();
       
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        //sort in basis of first element
        sort(pairs.begin(),pairs.end(),compareInterval);
        vector<int> ans(n+1,1);
        ans[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(pairs[j][1]<pairs[i][0]){
                    ans[i]=max(ans[i],1+ans[j]);
                }
            }
            maxsofar=max(maxsofar,ans[i]);
        }
        return maxsofar;
        
    }
};
