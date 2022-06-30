
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        long long s=0,avg=0,ans=0;
        sort(nums.begin(),nums.end());
        if(n%2) s=nums[n/2];
        else s=(nums[n/2]+nums[n/2-1])/2;

        for(int i=0;i<n;i++){
            ans+=(abs(nums[i]-s));
        }
        return ans;
    }
};
