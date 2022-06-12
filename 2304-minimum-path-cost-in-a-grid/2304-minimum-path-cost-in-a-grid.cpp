class Solution {
public:
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& moveCost) {
        int m=a.size();
        int n=a[0].size();
         vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=a[0][i];
        }
         int mainMin=INT_MAX;
        for(int i=1;i<m;i++){
            mainMin=INT_MAX;
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    mini=min(mini,a[i][j]+dp[i-1][k]+moveCost[a[i-1][k]][j]);
                }
                dp[i][j]=mini;
                mainMin=min(mainMin,dp[i][j]);
            }
        }
        // for(auto it1:dp){
        //     for(auto it2:it1) cout<<it2<<" ";
        //     cout<<endl;
        // }
        return mainMin;
    }
};
