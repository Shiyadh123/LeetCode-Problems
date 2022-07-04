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
    TreeNode* createNode(vector<int>& preorder,int s,int e){
      if(s>e) return NULL;
      int rootVal=preorder[s];
      TreeNode* newNode=new TreeNode(rootVal);
      int lo=s+1,hi=e;
      while(lo<=hi){
        int mid=(lo+hi)/2;
        if(preorder[mid]<rootVal) lo=mid+1;
        else hi=mid-1;
      }
      newNode->left=createNode(preorder,s+1,hi);
      newNode->right=createNode(preorder,hi+1,e);
      return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createNode(preorder,0,preorder.size()-1);
    }
};