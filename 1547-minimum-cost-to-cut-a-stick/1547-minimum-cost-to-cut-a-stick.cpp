
class Solution {
public:

    // int findMinCost(int i,int j,vector<int> breakPoints,vector<vector<int>>& dp){
    //     if(i+1==j) return 0;
    //     if(dp[i][j]!=-1) return  dp[i][j];
    //     int cost=INT_MAX;
        // for(int k=i+1;k<j;k++){
        //     cost=min(cost,breakPoints[j]-breakPoints[i]+findMinCost(i,k,breakPoints,dp)+findMinCost(k,j,breakPoints,dp));
        // }
    //     dp[i][j]=cost;
    //     return cost;
    // }
    int minCost(int n, vector<int>& cuts) {
        vector<int> breakPts(1,0);
        for(auto i:cuts) breakPts.push_back(i);
        breakPts.push_back(n);
        sort(breakPts.begin(),breakPts.end());
        int len=breakPts.size();
        vector<vector<int>> dp(len,vector<int> (len,0));
        // return findMinCost(0,len-1,breakPts,dp);
        for(int i=len-2;i>=0;i--){
            for(int j=i+2;j<len;j++){
                int cost=INT_MAX;
                 for(int k=i+1;k<j;k++){
                    cost=min(cost,breakPts[j]-breakPts[i]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=cost;
            }
        }
        return dp[0][len-1];
    }
};