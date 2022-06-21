class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(cost);
        for(int i=1;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],i>1?dp[i-2]:0);
        }
        return min(dp[n-1],dp[n-2]);
    }
};