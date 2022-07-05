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
    void recoverTree(TreeNode* root) {
        TreeNode* first1=NULL,*first2=NULL,*second=NULL;
        TreeNode* prev=NULL;
        while(root){
            if(root->left){ 
                TreeNode* temp=root->left;
                while(temp->right&&temp->right!=root) temp=temp->right;
                if(temp->right ==root) {
                    temp->right=NULL;
                    if(prev&&(prev->val>root->val)){
                        // cout<<prev->val<<" ";
                        if(!first1) {first1=prev; first2=root;}
                        else second =root;
                    }
                    prev=root;
                    root=root->right;
                }
                else {temp->right=root; root=root->left;}

            }else{
                 if(prev&&(prev->val>root->val)){
                        // cout<<prev->val<<" ";
                        if(!first1) {first1=prev; first2=root;}
                        else second =root;
                    }
                prev=root;
                root=root->right;
            }
        }
        // cout<<first1->val<<" "<<first2->val<<" ";
         if(second){
             swap(first1->val,second->val);
         }else{
             swap(first1->val,first2->val);
         }
        return;
    }
};