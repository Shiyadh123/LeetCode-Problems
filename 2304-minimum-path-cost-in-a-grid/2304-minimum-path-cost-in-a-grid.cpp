class Solution {
public:
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& moveCost) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        
    dp[0]=a[0];
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    mini=min(mini,a[i][j]+dp[i-1][k]+moveCost[a[i-1][k]][j]);
                }
                dp[i][j]=mini;
            }
        }
         
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};
