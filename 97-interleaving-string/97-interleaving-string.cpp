class Solution {
public:
    int l1,l2,l3;
    string ss1,ss2,ss3;
    bool fun(int i,int j,int k,vector<vector<int>> &memo){
        if(i>=l1&&j>=l2&&k>=l3) return true;
        if(memo[i][j]!=-1) return memo[i][j];
        bool x=false,y=false;
        if(i<l1&&ss1[i]==ss3[k]){
            x=fun(i+1,j,k+1,memo);
        }
        if(j<l2&&ss2[j]==ss3[k]){
            y=fun(i,j+1,k+1,memo);
        }
        memo[i][j]=x||y;
        return x||y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        ss1=s1; l1=s1.length();
        ss2=s2; l2=s2.length();
        ss3=s3; l3=s3.length();
        vector<vector<int>> memo(l1+1,vector<int> (l2+1,-1));
        return fun(0,0,0,memo);
    }
};