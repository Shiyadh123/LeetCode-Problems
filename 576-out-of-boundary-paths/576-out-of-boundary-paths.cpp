class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};const int MOD = 1e9 + 7;
    vector<vector<vector<long long >>> memo;
    bool isOut(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n) return 1;
        else return 0;
    }
    int dfs(int i,int j,int maxMoves,int m,int n,vector<vector<vector<long long >>> &memo){
        if(isOut(i,j,m,n)) return 1;
        if(maxMoves<=0) return 0;
        if(memo[i][j][maxMoves]!=-1) return memo[i][j][maxMoves];
        long long paths=0;
        for(auto dir:dirs){
            paths+=dfs(i+dir[0],j+dir[1],maxMoves-1,m,n,memo);
            paths=paths%MOD;
        }
        memo[i][j][maxMoves] =paths;
        return paths;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(m,vector<vector<long long > >(n,vector<long long >(maxMove+1,-1)));
        return dfs(startRow,startColumn,maxMove,m,n,memo)%MOD;
    }
};