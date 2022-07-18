class Solution {
public:
    bool isSplittable(vector<int>& nums,int sum,int m){
        int n=nums.size();
        int partitions=0;
        int currSum=0;
        for(int i=0;i<n;i++){
            if(currSum+nums[i]>sum){
                partitions++;
                currSum=nums[i];
            }else{
                currSum+=nums[i];
            }
        }
        partitions++;
        return (partitions<=m);
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isSplittable(nums,mid,m)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
