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
    int depth(TreeNode* root,bool isLeft){
        int cnt=0;
        while(root){
            cnt++;
            root=(isLeft?root->left:root->right);
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftDepth=depth(root,1);
        int rightDepth=depth(root,0);
        if(leftDepth==rightDepth) return pow(2,rightDepth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};