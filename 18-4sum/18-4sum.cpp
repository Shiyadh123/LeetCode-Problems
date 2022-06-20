class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n=nums.size();
         vector<vector<int>> ans;
         sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum2tar=(long long)target-nums[i]-nums[j];
                int left=j+1,right=n-1;
                while(left<right){
                    long long   currSum=(long long)nums[left]+nums[right];
                    if(currSum>sum2tar)  right--;
                    else if(currSum<sum2tar) left++;
                    else {
                        vector<int> quad={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(quad);
                        while(left<right&&nums[left]==quad[2]) left++;
                        while(left<right&&nums[right]==quad[3]) right--;
                    }
                }
                while(j+1<n&&nums[j]==nums[j+1]) j++;
            }
            while(i+1<n&&nums[i]==nums[i+1]) i++;
        }
        return  ans;
    }
};