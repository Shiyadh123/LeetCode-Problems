class Solution {
public:
    int fun(vector<int>& nums,int i, int curr,int target){
        if(i==0){
            return  (curr-nums[i]==target)+ (curr+nums[i]==target);
        }
        return fun(nums,i-1,curr-nums[i],target)+fun(nums,i-1,curr+nums[i],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return fun(nums,n-1,0,target);
    }
};