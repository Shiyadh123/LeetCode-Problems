class Solution {
public:
    int fun(int i,vector<int>& prices,int buy){
        if(i==prices.size()) return 0;
        if(buy){
            return max(-1*prices[i]+fun(i+1,prices,0),fun(i+1,prices,1));
        }else{
            return max(prices[i]+fun(i+1,prices,1), fun(i+1,prices,0));
        }
    }
    int maxProfit(vector<int>& prices) {
        // return fun(0,prices,1);
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int> (n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                if(!b) dp[b][i]=max(prices[i]+dp[1][i+1],dp[0][i+1]);
                else dp[b][i]=max(-prices[i]+dp[0][i+1],dp[1][i+1]);
            }
        }
        return dp[1][0];
    }
};