class Solution {
public:
    int countSubstrings(string s) {
          int l=s.length();
        if(l==1) return 1;
        int cnt=0;
        vector<vector<int>> dp(l,vector<int> (l,0));
        for(int i=0;i<l;i++){
            for(int j=0;j<(l-i);j++){
                if(j==i+j) dp[j][i+j]=1;
                else dp[j][i+j]=s[j]==s[i+j]&&(j+1==i+j||dp[j+1][i+j-1]);                                   
                if(dp[j][i+j]) cnt++;
            }
        }
        return cnt;
    }
};