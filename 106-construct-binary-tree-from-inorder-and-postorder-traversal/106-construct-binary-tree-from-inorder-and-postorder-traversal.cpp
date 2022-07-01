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
    TreeNode* fun(vector<int> inorder,vector<int> postorder,int iS,int iE,int pS,int pE,int n){
        if(pS>pE) return NULL;
        int rootVal=postorder[pE];
        int rootInd=find(inorder.begin()+iS, inorder.begin()+iE, rootVal)-inorder.begin();
        int Lcount=rootInd-iS,Rcount=iE-rootInd;
        TreeNode* node=new TreeNode(rootVal);
        node->left=fun(inorder,postorder,iS,rootInd-1,pS,pS+Lcount-1,n);
        node->right=fun(inorder,postorder,rootInd+1,iE,pS+Lcount,pE-1,n);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return fun(inorder,postorder,0,n-1,0,n-1,n);
    }
};
