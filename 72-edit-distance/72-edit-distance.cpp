class Solution {
public:
    //  int fun(string a,string b,int i,int j){
    //     if(i==-1) return j+1;
    //     if(j==-1) return i+1;

    //     if(a[i]==b[j]) 
    //     {
    //         return fun(a,b,i-1,j-1);
    //     }else{
    //         return 1+min(fun(a,b,i,j-1),min(fun(a,b,i-1,j),fun(a,b,i-1,j-1)));
    //     }
    //  }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        // return fun(word1,word2,word1.length(),word2.length());
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
         for(int i=0;i<=n;i++) dp[0][i]=i;
         for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                     dp[i][j]=1+min( dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};