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
    bool getPath(TreeNode* root, int value,string &path){
        if(!root) return false;
        if(root->val ==value) return true;
        path.push_back('L');
        if(getPath(root->left,value,path)) return true;
        path.pop_back();
        path.push_back('R');
        if(getPath(root->right,value,path)) return true;
        path.pop_back();
        return false;
    }
    void trimPrefix(string &a,string &b){
        int la=a.length();
        int lb=b.length();
        int i=0,j=0;
        while(i<la&&j<lb&&a[i]==b[j]) {
            i++;j++;
        }
        string c(la-i,'U');
        a=c;
        b=b.substr(j);
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string Spath="",Dpath="";
        getPath(root,startValue,Spath);
        getPath(root,destValue,Dpath);
        trimPrefix(Spath,Dpath);
        return Spath+Dpath;
    }
};