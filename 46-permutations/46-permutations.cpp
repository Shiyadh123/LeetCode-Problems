class Solution {
public:
    void fun(vector<int> perm,vector<vector<int>> &ans,unordered_map<int,int> isPicked,vector<int> nums){
        if(perm.size()==nums.size()){
            ans.push_back(perm); return;
        }
        for(auto i:nums){
            if(isPicked[i]) continue;
            perm.push_back(i);
            isPicked[i]++;
            fun(perm,ans,isPicked,nums);
            perm.pop_back();
            isPicked[i]--;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> isPicked;
        vector<vector<int>> ans;
        vector<int> perm;
        fun(perm,ans,isPicked,nums);
        return ans;
    }
};