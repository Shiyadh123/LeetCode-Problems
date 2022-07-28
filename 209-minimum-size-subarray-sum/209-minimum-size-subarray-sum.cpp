class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,minLen=INT_MAX,left=0,right=0,n=nums.size();
        sum=nums[0];
        while(left<n&&right<n){
            if(sum<target){
                right++; sum+=(right<n?nums[right]:0);
            }else{
                minLen=min(minLen,right-left+1);
                left++;  sum-=(left<n?nums[left-1]:0);
            }
        }
        return (minLen==INT_MAX?0:minLen);
    }
};