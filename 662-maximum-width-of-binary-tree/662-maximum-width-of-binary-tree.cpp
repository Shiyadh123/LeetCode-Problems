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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth=0;
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        while(!q.empty()){
            int size=q.size();
            int firstIndex=q.front().second;
            int lastIndex;
            int diffToOne=q.front().second-1;
            while(size--){
                pair<TreeNode*,long long > curr=q.front(); q.pop();
                if(curr.first->left) q.push({curr.first->left,2*(curr.second-diffToOne)});
                if(curr.first->right) q.push({curr.first->right,2*(curr.second-diffToOne)+1});
                lastIndex =curr.second;
            }
            if((lastIndex-firstIndex+1)>maxWidth) maxWidth=lastIndex-firstIndex+1;
        }
        return maxWidth;
    }
};