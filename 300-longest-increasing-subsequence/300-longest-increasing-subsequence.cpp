class Solution {
public:
    // int fun(int i,int prevInd,vector<int>& nums){
    //     if(i==nums.size()) return 0;

    //     if(prevInd==-1||nums[i]>nums[prevInd]){
    //         return max(1+fun(i+1,i,nums),fun(i+1,prevInd,nums));
    //     }
    //     return fun(i+1,prevInd,nums);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // return fun(0,-1,nums);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
          for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(j-1==-1||nums[i]>nums[j-1]){
                    dp[i][j]=max(1+dp[i+1][i+1],dp[i+1][j]);
                }else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};