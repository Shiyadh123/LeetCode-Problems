class Solution {
public:
    // int fun(int i,int fee,int canBuy,vector<int>& prices){
    //     if(i==prices.size()) return 0;

    //     if(canBuy){
    //         return max(-prices[i]+fun(i+1,fee,0,prices),fun(i+1,fee,1,prices));
    //     }else{
    //         return max(prices[i]-fee+fun(i+1,fee,1,prices),fun(i+1,fee,0,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        // return fun(0,fee,1,prices);
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        for(int i=n-1;i>=0;i--){
             dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
             dp[i][0]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};