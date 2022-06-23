class Solution {
public:
    void fun(int i,vector<int> curr,int target,vector<vector<int>> &ans,vector<int> candidates){
       if(i>=candidates.size()||target<0) return ;
        if(target==0) {ans.push_back(curr); return;}

        curr.push_back(candidates[i]);
        fun(i,curr,target-candidates[i],ans,candidates);
        curr.pop_back();
        fun(i+1,curr,target,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        fun(0,curr,target,ans,candidates);
        return ans;
    }
};