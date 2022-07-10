class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[0]=cost[0]; 
        dp[1]=cost[1]; 
         for(int j=2;j<n;j++){
            dp[j]=min(dp[j-1],dp[j-2])+cost[j];
        }
        return min(dp[n-2],dp[n-1]);
    }
};