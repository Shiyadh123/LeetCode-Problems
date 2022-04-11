class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int m=a.size();
        int n=a[0].size();
        k=k%(m*n);
        vector<vector<int>> ans(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[(i+((k+j)/n))%m][(j+k)%n]=a[i][j];
            }
        }
        return ans;
    }
};