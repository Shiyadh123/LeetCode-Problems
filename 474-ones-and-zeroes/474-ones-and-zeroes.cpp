class Solution {
public:
    int findMaxForm(vector<string>& strs, int n, int m) {
        int len=strs.size();
        vector<int> ones(len,0);
        vector<int> zeros(len,0);
        for(int i=0;i<len;i++){
           int a=0,b=0;
           for(auto j:strs[i]){
            if(j=='1') a++;
            else b++;
           }
           ones[i]=a; zeros[i]=b;
        }
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=0;i<len;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int notPick=(i==0)?0:dp[i-1][j][k];
                    int pick=0;
                    if(ones[i]<=j&&zeros[i]<=k) pick=1+((i==0)?0:dp[i-1][j-ones[i]][k-zeros[i]]);
                    dp[i][j][k]=max(pick,notPick);
                }
            }
        }
        return dp[len-1][m][n];
    }
};