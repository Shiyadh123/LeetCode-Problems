class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long sum=0;
        long long  cnt=0;
        int left=0,right=0;
        while(right<n){
            sum+=nums[right];
            while(((long long)sum*(right-left+1))>=k){
                sum-=nums[left];
                left++;
            }
            // cout<<left<<" "<<right<<endl;
           cnt+=(right-left+1);
           right++; 
        }
        return cnt;
    }
};