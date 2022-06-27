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
        stack<TreeNode*> st1,st2;
        st1.push(root);
        vector<int> row;
        while(!st1.empty()||!st2.empty()){
            
            while(!st1.empty()){
                TreeNode* tmp=st1.top(); st1.pop();
                if(tmp->left) st2.push(tmp->left);
                if(tmp->right) st2.push(tmp->right);
                row.push_back(tmp->val);
            }
            zigZag.push_back(row);
            row.clear();
            while(!st2.empty()){
                TreeNode* tmp=st2.top(); st2.pop();
                if(tmp->right) st1.push(tmp->right);
                if(tmp->left) st1.push(tmp->left);
                row.push_back(tmp->val);
            }
            if(!row.empty()) zigZag.push_back(row);
            row.clear();
        }         
        return zigZag;
    }
};