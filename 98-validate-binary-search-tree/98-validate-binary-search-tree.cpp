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
    bool check(TreeNode* root,TreeNode* maxNode,TreeNode* minNode){
      if(!root) return true;
      if((maxNode&&(root->val>=maxNode->val))||(minNode&&(root->val<=minNode->val))) return false;
      return check(root->left,root ,minNode)&&check(root->right,maxNode,root);

    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
};
