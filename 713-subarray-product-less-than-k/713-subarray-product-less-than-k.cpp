class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long prod=1;
        int cnt=0;
        int left=0,right=0;
        while(right<n){
            prod*=nums[right];
            while(prod>=k&&left<=right){
                prod/=nums[left];
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
};
