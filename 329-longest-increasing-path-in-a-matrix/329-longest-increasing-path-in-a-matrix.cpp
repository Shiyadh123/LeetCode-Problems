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
    int fun(vector<vector<int>>& nums,vector<vector<int>>& vis,int i,int j,int len,vector<vector<int>>& memo){
        vis[i][j]=1;
        int flg=0;//terminal position
        int ans=0;
        if(isOk(nums,vis,i+1,j,i,j)) { if(memo[i+1][j]==0) ans=max(ans,fun(nums,vis,i+1,j,len+1,memo)); else ans=max(ans,memo[i+1][j]); flg=1;}
        if(isOk(nums,vis,i,j+1,i,j)) { if(memo[i][j+1]==0) ans=max(ans,fun(nums,vis,i,j+1,len+1,memo));  else ans=max(ans,memo[i][j+1]); flg=1;}
        if(isOk(nums,vis,i,j-1,i,j)) { if(memo[i][j-1]==0) ans=max(ans,fun(nums,vis,i,j-1,len+1,memo)); else ans=max(ans,memo[i][j-1]);  flg=1;}
        if(isOk(nums,vis,i-1,j,i,j)) { if(memo[i-1][j]==0) ans=max(ans,fun(nums,vis,i-1,j,len+1,memo)); else ans=max(ans,memo[i-1][j]); flg=1;}
        vis[i][j]=0;
        if(flg==0){
            memo[i][j]=max(memo[i][j],1);
            return 1;
        }
        memo[i][j]=max(memo[i][j],ans+1);
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& nums) {
         int m=nums.size();
         int n=nums[0].size();
         int ans=0;
         vector<vector<int>> vis(m,vector<int> (n,0));
         vector<vector<int>> memo(m,vector<int> (n,0));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(memo[i][j]==0)
                ans=max(ans,fun(nums,vis,i,j,1,memo));
            }
        }
         
        return ans ;
            }
};
