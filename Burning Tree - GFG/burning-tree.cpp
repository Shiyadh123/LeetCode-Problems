// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node* findAdr( Node* r,int target ){
        if(!r) return NULL;
        if(r->data==target) return r;
        Node* left=findAdr(r->left,target);
        if(left) return left;
        Node* right=findAdr(r->right,target);
        if(right) return right;
        return NULL;
    }
    void makeGraph(Node* root,unordered_map<Node*,vector<Node*>>& adj){
        if(!root ) return;
        if(root->left){
            adj[root->left].push_back(root);
            adj[root].push_back(root->left);
            makeGraph(root->left,adj);
        }
        if(root->right){
            adj[root->right].push_back(root);
            adj[root].push_back(root->right);
            makeGraph(root->right,adj);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* tarPos=findAdr(root,target);
        unordered_map<Node*,vector<Node*>> adj;
        makeGraph(root,adj);
        queue<Node*> q;
        unordered_set<Node*> isVisited;
        q.push(tarPos);
        int count=0;
         while(!q.empty()){
            int size=q.size();
            while(size--){
                Node* curr=q.front(); q.pop();
                isVisited.insert(curr);
                for(auto neighbour:adj[curr]){
                    if(isVisited.count(neighbour)==0) q.push(neighbour);
                }
            }
            count++;
         }
         return count-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends