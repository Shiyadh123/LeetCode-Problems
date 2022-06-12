class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int> mp;
        int sum=0;
        int maxSum=0;
        int left=0,right=0;
        while(right<n){
            while(mp.find(nums[right])!=mp.end()){
                mp.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            sum+=nums[right];
            maxSum=max(maxSum,sum);
            mp.insert(nums[right]);
            right++;
        }
        return maxSum;
    }
};