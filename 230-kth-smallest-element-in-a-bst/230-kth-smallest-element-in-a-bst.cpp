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
    void fun(TreeNode* ptr,vector<int>& vals){
        if(ptr==NULL) return;

        fun(ptr->left,vals);
        vals.push_back(ptr->val);
        fun(ptr->right,vals);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        fun(root,vals);
        return vals[k-1];
    }
};