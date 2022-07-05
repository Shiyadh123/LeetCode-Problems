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
     TreeNode* first1=NULL,*first2=NULL,*second=NULL;
     void doInorder(TreeNode* root ){
        stack<TreeNode*> st;
        TreeNode* prev=NULL;
        while(root||(!st.empty())){
            while(root){
                st.push(root); root=root->left;
            }
            root=st.top(); st.pop();
            if(prev&&(prev->val>root->val)){
                
                if(first1){
                    second=root;
                }else{
                    first1=prev; first2=root;
                }
            }
            prev=root;
            root=root->right;
        }
        // cout<<first1->val;
        return;
    }
    void recoverTree(TreeNode* root) {
        first1=NULL;first2=NULL;second=NULL;
        doInorder(root);
         if(second){
             swap(first1->val,second->val);
         }else{
             swap(first1->val,first2->val);
         }
        return;
    }
};