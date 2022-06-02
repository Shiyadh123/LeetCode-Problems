class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l=s.length();
        // string t=s;
        // reverse(s.begin(),s.end());       
        // vector<vector<int>> dp(l+1,vector<int>(l+1,0));
        // for(int i=1;i<=l;i++){
        //     for(int j=1;j<=l;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[l][l];
        vector<vector<int>> dp(l,vector<int>(l,0));
        for(int j=0;j<l;j++){
            for(int i=0;i+j<l;i++){
                if(i==j+i) dp[i][j+i]=1;
                else if(s[i]==s[j+i]) dp[i][j+i]=2+dp[i+1][j+i-1];
                else dp[i][j+i]=max(dp[i+1][j+i],dp[i][j+i-1]);
            }
        }
        return dp[0][l-1];
    }
};