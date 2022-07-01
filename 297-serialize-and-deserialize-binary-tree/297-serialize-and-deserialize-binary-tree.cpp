/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string nl="null";
        string res="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front(); q.pop();
            if(curr==NULL){
                res+=nl;
            }else{
                res+=(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            }
            res+=",";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream str_strm(data);
        std::string tmp;
        vector<string> words;
        char delim = ',';  

        while (std::getline(str_strm, tmp, delim)) {
            words.push_back(tmp);
        }
        int i=1,n=words.size();
        queue<TreeNode*> q;
       TreeNode* temp=NULL;
        if(words[0]!="null") temp= new TreeNode(stoi(words[0]));
        q.push(temp);
        while(!q.empty()&&i<n){
            TreeNode* curr=q.front(); q.pop();
            if(curr==NULL) continue;
           
            TreeNode* temp2=(words[i]!="null"?new TreeNode(stoi(words[i])):NULL);
            curr->left=temp2;
            q.push(temp2);
             i++;
            TreeNode* temp3=(words[i]!="null"?new TreeNode(stoi(words[i])):NULL);
            curr->right=temp3;
            q.push(temp3);
            i++;
        }
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));