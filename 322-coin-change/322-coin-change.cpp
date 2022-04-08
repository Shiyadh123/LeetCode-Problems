class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int> (amount+1,1000001));
        
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=1000001;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                
                int notPick=dp[i-1][j];
                
                int pick=1000001;
                if(coins[i]<=j){
                    pick=1+dp[i][j-coins[i]];
                }
                
                dp[i][j]=min(pick,notPick);
            }
        }
        return (dp[n-1][amount]==1000001?-1:dp[n-1][amount]);
    }
    
};