class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(),-1*1e9);
        int n=nums.size();
        dp[n-1]=nums[n-1];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--){
                while(pq.top().second>i+k) {
                    pq.pop();
                }
                dp[i]=max(dp[i], nums[i]+pq.top().first);
                pq.push({dp[i],i});
        }
        return dp[0];
    }
};