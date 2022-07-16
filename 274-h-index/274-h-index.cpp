class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(),greater<>());
        int left=0,right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid+1<=nums[mid]) left=mid+1;
            else right=mid-1;
        }
        return right+1;
    }
};