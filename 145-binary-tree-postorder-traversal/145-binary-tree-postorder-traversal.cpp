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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
                vector<int> ans;

        if(!root) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode * curr=st.top(); st.pop();
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
            ans.push_back(curr->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};