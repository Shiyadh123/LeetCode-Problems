class Solution {
public:
// int fun(string s, string t ,int i,int j){
//     if(j==-1) return 1;
//     if(i==-1) return 0;
//     if(s[i]==t[j]){
//         return fun(s,t,i-1,j)+fun(s,t,i-1,j-1);
//     }else{
//         return fun(s,t,i-1,j);
//     }
// }
    int numDistinct(string s, string t) {
        
        int l1=s.length();
        int l2=t.length();
        vector<vector<int >> dp(l2+1,vector<int >(l1+1,0));
        for(int i=0;i<=l1;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=l2;i++){
            for(int j=1;j<=l1;j++){
                if(s[j-1]==t[i-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%1000000007;
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[l2][l1];
    }
};