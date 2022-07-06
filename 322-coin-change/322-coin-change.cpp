class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,10001));
        for(int i=0;i<=amount;i++){
            dp[0][i]=(i%coins[0]==0)?i/coins[0]:10001;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notChoose=dp[i-1][j];
                int choose=10001;
                if(coins[i]<=j){
                    choose=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(choose,notChoose);
            }
        }
        return dp[n-1][amount]==10001?-1:dp[n-1][amount];
    }
};