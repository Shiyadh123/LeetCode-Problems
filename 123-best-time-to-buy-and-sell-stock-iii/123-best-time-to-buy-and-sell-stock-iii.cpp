class Solution {
public:
    // int fun(int i,int txn,vector<int>& prices){
    //     if(i==prices.size()||txn==4) return 0;
    //     if(txn%2==0){
    //         return max(-1*prices[i]+fun(i+1,txn+1,prices),fun(i+1,txn,prices));
    //     }else{
    //         return max(prices[i]+fun(i+1,txn+1,prices),fun(i+1,txn,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        // return fun(0,0,prices);
        int n=prices.size();
        vector<vector<int>> dp(5,vector<int>(n+1,0));
        for(int i=3;i>=0;i--){
            for(int k=n-1;k>=0;k--){
                if(i%2){
                    dp[i][k]=max(prices[k]+dp[i+1][k+1],dp[i][k+1]);
                }else{
                    dp[i][k]=max(-1*prices[k]+dp[i+1][k+1],dp[i][k+1]);
                }
                 
            }
        }
        return dp[0][0];
    }
};