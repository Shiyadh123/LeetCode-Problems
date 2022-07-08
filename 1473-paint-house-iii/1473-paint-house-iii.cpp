class Solution {
public:
    int dp[101][101][21]={};
    int findCost(int i,int lstCol,vector<int>& houses, vector<vector<int>>& cost,int tar){
        int m=houses.size(); int n=cost[0].size();
        
        if(i>=m||tar<0){
            if(tar==0)  return 0;
            else  return 1000001;
        }
        if(houses[i]!=0) return findCost(i+1,houses[i],houses,cost,tar-(lstCol!=houses[i]));
        
        if(dp[i][tar][lstCol]) {return dp[i][tar][lstCol];}
        int mini=1000001;
        if(houses[i]==0){
            for(int p=1;p<=n;p++){
                mini=min(mini,cost[i][p-1]+findCost(i+1,p,houses,cost,tar-(lstCol!=p)));
            }
        }
        return dp[i][tar][lstCol]=mini;
          
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // memset(dp,-1,sizeof(dp));
        int minCost=findCost(0,0,houses,cost,target);
        return minCost>=1000001?-1:minCost;
    }
};