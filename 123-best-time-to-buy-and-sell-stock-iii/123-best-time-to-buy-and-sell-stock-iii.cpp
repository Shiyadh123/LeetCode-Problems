class Solution {
public:
    // int fun(int i,int canBuy,int cap,vector<int>& prices){
    //     if(i==prices.size()||cap==0) return 0;
    //     if(canBuy){
    //         return max(-1*prices[i]+fun(i+1,0,cap,prices),fun(i+1,1,cap,prices));
    //     }else{
    //         return max(prices[i]+fun(i+1,1,cap-1,prices),fun(i+1,0,cap,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        // return fun(0,1,2,prices);
        int n=prices.size();
         vector<vector<vector<int>>> dp(3,vector<vector<int>>(2,vector<int>(n+1,0)));
         for(int i=1;i<3;i++){
            for(int k=n-1;k>=0;k--){
                for(int j=0;j<2;j++){
                    if(j==1){
                        dp[i][j][k]=max(-1*prices[k]+dp[i][0][k+1],dp[i][1][k+1]);
                    }else{
                        dp[i][j][k]=max(prices[k]+dp[i-1][1][k+1],dp[i][0][k+1]);
                    }
                }
            }
            // for(auto it:dp[i][0]) cout<<it<<" ";
            // cout<<endl;

            // for(auto it:dp[i][1]) cout<<it<<" ";
            // cout<<endl;
        }
        return dp[2][1][0];
    }
};