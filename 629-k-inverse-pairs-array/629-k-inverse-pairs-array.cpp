class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int> (k+1,0));
        for(int i=1;i<=n;i++){
            long long val=0;
            for(int j=0;j<=k;j++){
                if(i==1){
                    if(j==0) dp[i][j]= 1;
                    else dp[i][j]= 0;
                }else{
                    long long cnt=0;
                    val+=dp[i-1][j];
                    val-=((j-1-min(i-1,j)>=0)?dp[i-1][j-1-min(i-1,j)]:0);
                    // for(int p=0;p<=min(i-1,j);p++){
                    //     cnt+=(dp[i-1][j-p]);
                    //     cnt=cnt%MOD;
                    // }
                    dp[i][j] = val%MOD;
                }
            }
        }
        return dp[n][k];
    }
};