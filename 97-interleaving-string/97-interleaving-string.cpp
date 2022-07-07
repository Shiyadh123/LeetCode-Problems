class Solution {
public:
    string ss1,ss2,ss3;
    // bool fun(int i,int j,int k,vector<vector<int>> &memo){
    //     if(i<0&&j<0) return true;
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     bool x=false,y=false;
    //     if(i>=0&&ss1[i]==ss3[k]){
    //         x=fun(i-1,j,k-1,memo);
    //     }
    //     if(j>=0&&ss2[j]==ss3[k]){
    //         y=fun(i,j-1,k-1,memo);
    //     }
    //     memo[i][j]=x||y;
    //     return x||y;
    // }
    bool isInterleave(string s1, string s2, string s3) {
        int l1,l2,l3;
        ss1=s1; l1=s1.length();
        ss2=s2; l2=s2.length();
        ss3=s3; l3=s3.length();
        if(l1+l2!=l3) return false;
        vector<vector<int>> dp(l1+1,vector<int> (l2+1,0));
        // return fun(l1-1,l2-1,l3-1,memo);
        dp[0][0]=1;
         for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0&&j==0) continue;
                int k=i+j;
                bool x=false,y=false;
                if(i>0&&ss1[i-1]==ss3[k-1]){
                    x=dp[i-1][j];
                }
                if(j>0&&ss2[j-1]==ss3[k-1]){
                    y=dp[i][j-1];
                }
                dp[i][j]=x||y;
            }
        }
        // for(auto i:dp){
        //     for(auto j:i) cout<<j<<" ";cout<<endl;
        // }
        return dp[l1][l2];
    }
};