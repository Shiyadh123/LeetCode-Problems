class Solution {
public:
    void fun(int i,vector<int> sub,vector<int> nums,vector<vector<int>>& ans){
        ans.push_back(sub);
        if(i==nums.size()){
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i&&nums[j-1]==nums[j]) continue;
            sub.push_back(nums[j]);
            fun(j+1,sub,nums,ans);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        fun (0,sub,nums,ans);
        return ans;
    }
};