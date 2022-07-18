class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cnt=0;
        vector<vector<int>> prefix(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=matrix[i-1][j-1]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                unordered_map<int,int> lookUp={{0,1}};
                for(int k=0;k<n;k++){
                    int currSum=prefix[j+1][k+1]-prefix[i][k+1]-prefix[j+1][0]+prefix[i][0];
                    if(lookUp.find(currSum-target)!=lookUp.end()) cnt+=lookUp[currSum-target];
                    lookUp[currSum]++;
                }
            }
        }
        return cnt;
    }
};