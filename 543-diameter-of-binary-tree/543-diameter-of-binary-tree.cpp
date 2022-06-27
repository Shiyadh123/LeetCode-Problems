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
    int dia(TreeNode* root,int &maxDia){
        if(root==NULL) return 0;
        int LH=dia(root->left,maxDia);
        int RH=dia(root->right,maxDia);
        maxDia=max(maxDia,LH+RH);
        return 1+max(LH,RH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxDia=0;
        dia(root,maxDia);
        return maxDia;
    }
};