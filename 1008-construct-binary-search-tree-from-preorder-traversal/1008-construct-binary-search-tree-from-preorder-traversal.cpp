class Solution {
public:
    TreeNode* createNode(vector<int>& preorder,int& i,int ub){
      if(i>=preorder.size()||preorder[i]>=ub) return NULL;
      TreeNode* newNode=new TreeNode(preorder[i]);
        int currVal=preorder[i];
      ++i;
      newNode->left=createNode(preorder,i,currVal);
      newNode->right=createNode(preorder,i,ub);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return createNode(preorder,i,10001);
    }
};