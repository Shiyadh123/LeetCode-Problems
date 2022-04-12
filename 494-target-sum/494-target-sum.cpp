class Solution {
public:
    int fun(vector<int>& nums,int i,int target){
        if(i==0){
            return  (nums[0]==target)+(nums[0]==-1*target);
        }
        return fun(nums,i-1,target-nums[i])+fun(nums,i-1,target+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return fun(nums,n-1,target);
    }
};