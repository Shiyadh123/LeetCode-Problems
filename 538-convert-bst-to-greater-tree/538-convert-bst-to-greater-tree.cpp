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
void dfs(TreeNode* rt,int& sum){
    if(rt==NULL) return;
    dfs(rt->right,sum);
    sum+=(rt->val);
    rt->val=sum;
    dfs(rt->left,sum);
}
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        dfs(root,sum);
        return root;
    }
};