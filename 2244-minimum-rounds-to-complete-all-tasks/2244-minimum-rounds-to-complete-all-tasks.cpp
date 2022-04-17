class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //can b solved easily using observations as well
        vector<int> dp(100001,INT_MAX);
        int ans=0;
        dp[1]=INT_MAX;
        dp[2]=1;
        dp[3]=1;
        
        for(int i=4;i<100001;i++){
            dp[i]=1+min(dp[i-2],dp[i-3]);
        }
        
        unordered_map<int,int> mp;
        for(auto i:tasks){
            mp[i]++;
        }
        
        for(auto i:mp){
            if(dp[i.second]==INT_MAX) return -1;
            ans+=(dp[i.second]);
        }
        
        return ans;
    }
};