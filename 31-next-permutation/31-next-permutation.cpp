class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n=nums.size();
         int ind=-1;
        
         if(n==0||n==1) return;
         for(int i=n-1;i>=1;i--){
             if(nums[i-1]<nums[i]){
                ind=i-1;
                 break;
             }
         }
         for(int j=n-1;(j>=0&&ind!=-1);j--){
             if(nums[ind]<nums[j]){
                 swap(nums[ind],nums[j]);
                 break;
             }
          }
        reverse(nums.begin()+ind+1,nums.end());
    }
};