class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> > dp(n,vector<int> (amount+1,0));
        
        for(int j=0;j<=amount;j++){
            dp[0][j]=(j%coins[0]?0:1);
            
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int NotPick=dp[i-1][j];
                int pick=0;
                if(coins[i]<=j){
                    pick=dp[i][j-coins[i]];
                }
                dp[i][j]=pick+NotPick;
            }
        }
        
        return dp[n-1][amount]; 
        
        }
};