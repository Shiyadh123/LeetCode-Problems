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
    int checkBal(TreeNode* root){
        if(root==NULL) return 0;
        int leftH=checkBal(root->left);
        int rightH=checkBal(root->right);
        if(leftH==-1||rightH==-1) return -1;
        if(abs(leftH-rightH)>1) return -1;
        return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(checkBal(root)==-1) return false;
        else return true;
        
    }
};