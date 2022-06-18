class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int toFind=-nums[i];
            int left=i+1,right=n-1;
            while(left<right){
                if(left==i) {
                    left++;
                    continue;}
                if(right==i){
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==toFind) {
                    vector<int> temp={nums[i],nums[left],nums[right]};
                    // sort(temp.begin(),temp.end());
                    ans.insert(temp);
                    right--;left++;
                }else if(nums[left]+nums[right]>toFind) right--;
                else left++;              
            }
        }
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};