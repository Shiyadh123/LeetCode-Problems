class Solution {
public:
    // int fun(string s, string p,int i,int j){
    //     if((i==-1)&&j==-1)  return 1; 
    //     if(j==-1) {
    //         for(int k=0;k<=i;k++) if(s[k]!='*') return 0;
    //         return 1;
    //     }
    //     if(i==-1) return 0;
    //     if(s[i]=='?') return fun(s,p,i-1,j-1);
    //     if(s[i]==p[j]) return fun(s,p,i-1,j-1);
    //     if(s[i]=='*') return fun(s,p,i,j-1)||fun(s,p,i-1,j);
    //     return 0;
    // }
    bool isMatch(string s, string p) {
        // return fun(p,s,p.length()-1,s.length()-1);
        int m=s.length();
        int n=p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            if(i==0) dp[0][i]=1;
            else{
                if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
                else dp[0][i]=0;
            }
        }
         for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[m][n];
    }
};