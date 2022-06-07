class Solution {
public:
    // int fun(int i,int canBuy,vector<int>& prices){
    //     if(i>=prices.size()) return 0;

    //     if(canBuy==1){
    //         return max(-1*prices[i]+fun(i+1,0,prices),fun(i+1,1,prices));
    //     }else  {
    //         return max(prices[i]+fun(i+2,1,prices),fun(i+1,0,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        // return fun(0,1,prices);
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};