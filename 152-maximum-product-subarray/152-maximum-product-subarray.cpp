class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        long long maxprod=1;
        long long minprod=1;
        int maxi=0;
        for(int i=0;i<n;i++){
            
            long long mp;
            mp= max(maxprod*nums[i],max((long long)nums[i],minprod*nums[i]));
            minprod= min(maxprod*nums[i],min((long long)nums[i],minprod*nums[i]));
            maxprod=mp;
            
            maxi=max((long long)maxi,maxprod);
           
        }
        return maxi;
    }
};