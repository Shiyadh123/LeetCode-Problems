class Solution {
public:
    // long long fun(int m, int n ,vector<vector<long long >> &pricesMap, vector<vector<long long >> &memo) {
    //     if(memo[m][n]!=-1) return memo[m][n];
    //     long long maxi=pricesMap[m][n];
    //      for(int i=1;i<m;i++){
    //         maxi=max(maxi,fun(i,n,pricesMap,memo)+fun(m-i,n,pricesMap,memo));
    //     }
    //      for(int i=1;i<n;i++){
    //         maxi=max(maxi,fun(m,i,pricesMap,memo)+fun(m,n-i,pricesMap,memo));
    //     }
    //     memo[m][n]=maxi;
    //     return maxi;
    // }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long >> pricesMap(m+1,vector<long long > (n+1,0));
        vector<vector<long long >> dp(m+1,vector<long long > (n+1,0));
          for(int i=0;i<prices.size();i++){
             pricesMap[prices[i][0]][prices[i][1]]=prices[i][2];
        }
         for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                long long maxi=pricesMap[i][j];
                for(int k=1;k<i;k++){
                    maxi=max(maxi,dp[k][j]+dp[i-k][j]);
                }
                for(int k=1;k<j;k++){
                    maxi=max(maxi,dp[i][k]+dp[i][j-k]);
                }
                dp[i][j]=max(dp[i][j],maxi);
            }
        }
        
        return dp[m][n];
        // return fun(m,n,pricesMap,memo);
    }
};