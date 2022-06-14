class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n=nums.size();
        //  bool npresent=false;
        //  for(int i=0;i<n;i++){
        //     if(nums[i]==n) npresent=true;
        //     if(nums[i]<=0) nums[i]=n;
        // }
        // for(int i=0;i<n;i++){
        //     if(abs(nums[i])<n) nums[abs(nums[i])]=-abs(nums[abs(nums[i])]);
        // }
        // for(int i=1;i<n;i++){
        //     if(nums[i]>0) return i;
        // }
        // return npresent?n+1:n;

        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};