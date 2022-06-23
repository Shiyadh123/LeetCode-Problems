class Solution {
public:
 void fun(int i,vector<int> curr,int target,set<vector<int>> &ans,vector<int> candidates){
        
        if(target==0) {ans.insert(curr); return;}
        if(i>=candidates.size()||target<0) return ;
        for(int j=i;j<candidates.size();j++){
             if(j==i||candidates[j]!=candidates[j-1]){
                curr.push_back(candidates[j]);
                fun(j+1,curr,target-candidates[j],ans,candidates);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end());
         set<vector<int>> ans;
         vector<int> curr;
         fun(0,curr,target,ans,candidates);
         vector<vector<int>> res(ans.begin(),ans.end());
         return res;
    }
};
