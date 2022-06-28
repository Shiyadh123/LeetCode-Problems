/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,map<int,vector<int>>> cols;
        q.push({root,0});
        int row=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<TreeNode*,int> curr=q.front(); q.pop();
                if(curr.first->left) q.push({curr.first->left,curr.second-1});
                if(curr.first->right) q.push({curr.first->right,curr.second+1});
                cols[curr.second][row].push_back(curr.first->val);
            }
            row++;
        }
        for(auto i:cols){
            vector<int> temp;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};