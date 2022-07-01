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
    TreeNode* fun(vector<int> preorder, vector<int> inorder,int pS,int pE,int iS,int iE,int n){
        if(pS>pE) return NULL;
        int rootVal=preorder[pS];
        int rootInd=find(inorder.begin()+iS, inorder.begin()+iE, rootVal)-inorder.begin();
        int Lcount=rootInd-iS,Rcount=iE-rootInd;
        TreeNode* node=new TreeNode(rootVal);
        node->left=fun(preorder,inorder,pS+1,pS+Lcount,iS,iS+Lcount,n);
        node->right=fun(preorder,inorder,pS+1+Lcount,pE,rootInd+1,iE,n);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return fun(preorder,inorder,0,n-1,0,n-1,n);
    }
};