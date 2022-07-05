class Solution {
public:
    long long fun(int m, int n ,vector<vector<long long >> &pricesMap, vector<vector<long long >> &memo) {
        if(memo[m][n]!=-1) return memo[m][n];
        long long maxi=pricesMap[m][n];
         for(int i=1;i<m;i++){
            maxi=max(maxi,fun(i,n,pricesMap,memo)+fun(m-i,n,pricesMap,memo));
        }
         for(int i=1;i<n;i++){
            maxi=max(maxi,fun(m,i,pricesMap,memo)+fun(m,n-i,pricesMap,memo));
        }
        memo[m][n]=maxi;
        return maxi;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long >> pricesMap(m+1,vector<long long > (n+1,0));
        vector<vector<long long >> memo(m+1,vector<long long > (n+1,-1));
          for(int i=0;i<prices.size();i++){
             pricesMap[prices[i][0]][prices[i][1]]=prices[i][2];
        }
        return fun(m,n,pricesMap,memo);
    }
};