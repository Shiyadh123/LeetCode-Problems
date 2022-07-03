class Solution {
public:
    const int MOD = 1e9 + 7;
    bool isOk(vector<vector<int>>& nums,vector<vector<int>>& vis,int i,int j,int p,int q){
        int m=nums.size();
         int n=nums[0].size();
         if(i<0||j<0||i>=m||j>=n||vis[i][j]!=0) return false;
         if(nums[i][j]<=nums[p][q]) return false;
         return true;
    }
    long long fun(vector<vector<int>>& nums,vector<vector<int>>& vis,int i,int j,int len,vector<vector<int>>& memo){
        vis[i][j]=1;
        int flg=0;
        long long ans=0;
        if(isOk(nums,vis,i+1,j,i,j)) { if(memo[i+1][j]==-1) ans+=fun(nums,vis,i+1,j,len+1,memo); else ans+=memo[i+1][j]; ans=ans%MOD; flg=1;}
        if(isOk(nums,vis,i,j+1,i,j)) { if(memo[i][j+1]==-1) ans+=fun(nums,vis,i,j+1,len+1,memo);  else ans+=memo[i][j+1]; ans=ans%MOD; flg=1;}
        if(isOk(nums,vis,i,j-1,i,j)) { if(memo[i][j-1]==-1) ans+=fun(nums,vis,i,j-1,len+1,memo); else ans+=memo[i][j-1];  ans=ans%MOD; flg=1;}
        if(isOk(nums,vis,i-1,j,i,j)) { if(memo[i-1][j]==-1) ans+=fun(nums,vis,i-1,j,len+1,memo); else ans+=memo[i-1][j]; ans=ans%MOD; flg=1;}
        vis[i][j]=0;
        if(flg==0){
            memo[i][j]=1;
            return 1;
        }
        // cout<<i<<" "<<j<<" "<<ans<<" "<<endl;
        memo[i][j]=ans+1;
        return ans+1;

    }
    int countPaths(vector<vector<int>>& nums) {
         int m=nums.size();
         int n=nums[0].size();
         long long ans=0;
         vector<vector<int>> vis(m,vector<int> (n,0));
         vector<vector<int>> memo(m,vector<int> (n,-1));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(memo[i][j]==-1)
                ans+=fun(nums,vis,i,j,1,memo);
                else 
                ans+=memo[i][j];
                ans=ans%MOD;
            }
        }
         
        return ans%MOD;
            }
};