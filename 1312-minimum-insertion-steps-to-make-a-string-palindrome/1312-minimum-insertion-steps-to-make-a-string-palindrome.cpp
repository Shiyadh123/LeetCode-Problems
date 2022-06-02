class Solution {
public:
    // int funToFindMinIns(string s ,int i,int j,vector<vector<int>> &memo){
    //     if(i>=j) return 0;
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     if(s[i]==s[j]){
    //         memo[i][j]=funToFindMinIns(s,i+1,j-1,memo);
    //         return memo[i][j];
    //     }
    //     memo[i][j]=1+min(funToFindMinIns(s,i+1,j,memo),funToFindMinIns(s,i,j-1,memo));
    //     return memo[i][j];
    // } 
    int minInsertions(string s) {
        int l=s.length();
        vector<vector<int>> dp(l,vector<int>(l,0));
        for(int i=0;i<l;i++){
            for(int j=0;j+i<l;j++){
                if(j==j+i){
                    dp[j][j+i]=0;
                }
                else if(s[j]==s[j+i]){
                     dp[j][j+i]=dp[j+1][i+j-1];
                }else{
                    dp[j][j+i]=1+min(dp[j][j+i-1],dp[j+1][j+i]);
                }
            }
        }
        return dp[0][l-1];
    }
    //OR
    // l-LCS(s)
};