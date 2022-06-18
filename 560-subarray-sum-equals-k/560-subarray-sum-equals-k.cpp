class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> cnt;
        cnt[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(cnt.find(sum-k)!=cnt.end()) ans+=cnt[sum-k];
            cnt[sum]++;
        }
        return ans;
    }
};