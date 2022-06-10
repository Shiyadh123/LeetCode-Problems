class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxLen=0;
        int cnt=0;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    if(1+dp[prev]>dp[i]){
                        dp[i]=1+dp[prev];
                        count[i]=count[prev];
                    }else if(1+dp[prev]==dp[i]){
                        count[i]+=count[prev];
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++) maxLen=max(maxLen,dp[i]);
        for(int i=0;i<n;i++){
            if(dp[i]==maxLen) cnt+=count[i];
        }
        
        return cnt;
    }
};