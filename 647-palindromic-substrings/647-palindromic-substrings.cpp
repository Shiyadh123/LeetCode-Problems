class Solution {
public:
    int expandPali(int left,int right,string s){
        int cnt=0;
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            cnt++;left--;right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int l=s.length();
        if(l==1) return 1;
        int cnt=0;
        // vector<vector<int>> dp(l,vector<int> (l,0));
        // for(int i=0;i<l;i++){
        //     for(int j=0;j<(l-i);j++){
                // if(j==i+j) dp[j][i+j]=1;
                // else dp[j][i+j]=s[j]==s[i+j]&&(j+1==i+j||dp[j+1][i+j-1]);                                   
                // if(dp[j][i+j]) cnt++;
        //     }
        // }
        for(int i=0;i<l;i++){
            cnt+=expandPali(i,i,s);
            cnt+=expandPali(i,i+1,s);
        }
        return cnt;
    }
};
