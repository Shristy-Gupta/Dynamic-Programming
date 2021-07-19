class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Array size
int n=prices.size();
//If array size <=0 return 0
if(n<=0){
return 0;
}
//Here we are trying to calculate max of second sell
// fb= first buy (minimize it ), fs=first sell(maximize it)
//sb=second buy (minimize it ), ss=second sell(maximize it)
//consider a wallet you have with 0 money and you want to maximize the wallet amount in second sell
int fb=INT_MIN,sb=INT_MIN;
int fs=0,ss=0;
for(int i=0;i<n;i++){
//first we will any way need to make a purchace therefore over wallet money we have is 0-prices[i]
// max is written because we are trying to maximize over all profit we have
fb=max(fb,-prices[i]);
//Then we first sell the purchased stock at + prices[i],therefore over wallet money we have is fb+prices[i]
// max is written because we are trying to maximize over all profit we have
fs=max(fs,prices[i]+fb);
// Then again we buy next stock therefore over wallet money we have is fs-prices[i] --> to make this amount
// we need to buy the prices[i] that is very small
sb=max(sb,fs-prices[i]);
// Again sell the stock so the net wallet amount will be sb+prices[i]
ss=max(ss,sb+prices[i]);
}
//return second sell
return ss;
    }
};
