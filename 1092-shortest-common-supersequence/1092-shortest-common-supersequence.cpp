class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();
        vector<vector<int>> dp(l1+1,vector<int> (l2+1,0));
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        // cout<<dp[l1][l2];
        int i=l1;
        int j=l2;
        string ans;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=(str1[i-1]);
                i--;j--;
            }else if(dp[i-1][j]==dp[i][j]){
                ans+=(str1[i-1]);
                i--;
            }else{
                ans+=(str2[j-1]);
                j--;
            }
        }
        while(i>0){
            ans+=(str1[i-1]);
            i--;
        }
        while(j>0){
            ans+=(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};