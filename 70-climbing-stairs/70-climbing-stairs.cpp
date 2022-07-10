class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,0);
        if(n==1) return 1;
        dp[0]=1;
        dp[1]=2; 
         for(int j=2;j<n;j++){
            dp[j]=dp[j-1]+dp[j-2];
        }
        return dp[n-1];
    }
};