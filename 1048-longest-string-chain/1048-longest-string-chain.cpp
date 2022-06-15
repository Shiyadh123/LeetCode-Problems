class Solution {
public:
  bool isPred(string a,string b){
        if(a.length()!=b.length()+1) return false;
        int i=0,j=0;
        while(j<a.length()){
            if(b[i]!=a[j]) {j++;}
            else {i++;j++;}
        }
        return (i==b.size()&&j==a.size())?true:false;
    }
    int longestStrChain(vector<string>& words) {
         int n=words.size();
         sort(words.begin(),words.end(), []
            (const std::string& first, const std::string& second){
                return first.size() < second.size();
            });
         vector<int> dp(n,1);
         for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]>=dp[i]&&isPred(words[i],words[j])){
                    dp[i]=1+dp[j];
                }
            }
        }
        // for(auto it:dp) cout<<it<<" ";
        return *max_element(dp.begin(),dp.end());
    }
};