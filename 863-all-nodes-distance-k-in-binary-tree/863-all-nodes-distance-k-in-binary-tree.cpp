/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> myParent;
        unordered_set<TreeNode*> isVisited;
        queue<TreeNode*> q;
        q.push(root);
        myParent[root]=NULL;
         while(!q.empty()){
             TreeNode* curr=q.front(); q.pop();
             if(curr->left) {
                myParent[curr->left]=curr;
                q.push(curr->left);
             }
             if(curr->right) {
                myParent[curr->right]=curr;
                q.push(curr->right);
             }
         }
        int dist=0;
        // for(auto i:myParent) cout<<i.first->val<<" "<<i.second->val<<endl;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(dist==k){
                while(size--) {ans.push_back(q.front()->val); q.pop();}
                return ans;
            }
            while(size--){
                TreeNode* curr=q.front(); q.pop();
                cout<<curr->val<<" ";
                isVisited.insert(curr);
                //left
                if((curr->left)&&(isVisited.find(curr->left)==isVisited.end())) q.push(curr->left);
                //right
                if((curr->right)&&(isVisited.find(curr->right)==isVisited.end())) q.push(curr->right);
                //parent
                if((myParent[curr])&&(isVisited.find(myParent[curr])==isVisited.end())) q.push(myParent[curr]);
            }
            dist++;
        }
        return ans;
    }
};