// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isMovable(int i,int j,int n,vector<vector<int>> m,vector<vector<int>> vis){
        if(i<0||j<0||i>=n||j>=n||vis[i][j]==1) return false;
        if(m[i][j]==0) return false;
        return true;
    }
    void fun(int i,int j,int n, string path, vector<string>& ans,vector<vector<int>> m,vector<vector<int>> vis){
        vis[i][j]=1;
        if(i==n-1&&j==n-1){
            ans.push_back(path); return;
        }
        if(isMovable(i-1,j,n,m,vis)){
            path.push_back('U');
            fun(i-1,j,n,path,ans,m,vis);
            path.pop_back();
        }
        if(isMovable(i+1,j,n,m,vis)){
            path.push_back('D');
            fun(i+1,j,n,path,ans,m,vis);
            path.pop_back();
        }
        if(isMovable(i,j+1,n,m,vis)){
            path.push_back('R');
            fun(i,j+1,n,path,ans,m,vis);
            path.pop_back();
        }
        if(isMovable(i,j-1,n,m,vis)){
            path.push_back('L');
            fun(i,j-1,n,path,ans,m,vis);
            path.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string path="";
        if(isMovable(0,0,n,m,vis)) fun(0,0,n,path,ans,m,vis);
        return ans;
    }
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends