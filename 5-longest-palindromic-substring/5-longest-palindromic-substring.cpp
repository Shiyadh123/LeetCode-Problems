class Solution {
public:
    string longestPalindrome(string s) {
        int l=s.length();
        if(l==1) return s;
        int st=0,en=0;
        vector<vector<int>> dp(l,vector<int> (l,0));
        for(int i=0;i<l;i++){
            for(int j=0;j<(l-i);j++){
                if(j==i+j) dp[j][i+j]=1;
                else{
                    if(s[j]!=s[i+j]) dp[j][i+j]=0;
                    else{
                        if(j+1==i+j) dp[j][i+j]=1;
                        else dp[j][i+j]=dp[j+1][i+j-1];
                    }
                }
                if(dp[j][i+j]) {st=j;en=i+j;}
            }
        }
        // for(auto i:dp){
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return s.substr(st,en-st+1);
    }
};