/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
                vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> lev;
            while(size--){
                Node* curr=q.front(); q.pop();
                lev.push_back(curr->val);
                for(auto i:curr->children){
                    if(i) q.push(i);
                }
            }
            ans.push_back(lev);
        }
        return ans;
    }
};