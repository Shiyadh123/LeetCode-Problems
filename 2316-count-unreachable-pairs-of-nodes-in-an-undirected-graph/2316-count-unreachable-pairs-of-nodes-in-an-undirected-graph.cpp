class Solution {
public:
    int fun(int i,vector<int> adj[],vector<int>& vis){
        if(vis[i]) return 0;
        int a=1;
        vis[i]=1;
        for(auto ad:adj[i]){
            if(vis[ad]==0) a+=(fun(ad,adj,vis));
        }
        return a;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        long long ans=0;
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
                if(vis[i]==0) {
                    long long k=(fun(i,adj,vis));
                    ans+=(k*(n-k));
                }
        }
        return ans/2;
    }
};