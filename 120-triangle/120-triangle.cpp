class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(triangle);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int top=INT_MAX,left=INT_MAX;
                if(j!=0) left=dp[i-1][j-1];
                if(j!=i) top=dp[i-1][j];
                dp[i][j]=min(top,left)+triangle[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};