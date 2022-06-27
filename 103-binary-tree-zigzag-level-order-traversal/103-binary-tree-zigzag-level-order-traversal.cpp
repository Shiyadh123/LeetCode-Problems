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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        if(root==NULL) return zigZag;
        queue<TreeNode*> q;
        q.push(root);
        bool LtoR=true;
        while(!q.empty()){
            vector<TreeNode*> level;
            while(!q.empty()){
                level.push_back(q.front()); q.pop();
            }
            for(auto i:level) {
                if(i->left) q.push(i->left);
                if(i->right) q.push(i->right);
            }
            if(!LtoR) reverse(level.begin(),level.end());
            LtoR=!LtoR;
            vector<int> vals;
            for(auto i:level) vals.push_back(i->val);
            zigZag.push_back(vals);
        }
        return zigZag;
    }
};