class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[0][i]=10001;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int notChoose=dp[i-1][j];
                int choose=10001;
                if(coins[i-1]<=j){
                    choose=1+dp[i][j-coins[i-1]];
                }
                dp[i][j]=min(choose,notChoose);
            }
        }
        return dp[n][amount]==10001?-1:dp[n][amount];
    }
};