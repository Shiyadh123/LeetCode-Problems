class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=INT_MIN;
        vector<vector<int>> prefix(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=matrix[i-1][j-1]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int p=0,q=0;
                set<int> st;
                st.insert(0);
                while(q<n){
                    int currSum=prefix[j+1][q+1]-prefix[i][q+1]-prefix[j+1][p]+prefix[i][p];
                    auto target=st.lower_bound(currSum-k);
                    if(target!=st.end()){
                        maxi=max(maxi,currSum-*target);
                    }
                    st.insert(currSum);
                    q++;
                }
            }
        }
        return maxi;
    }
};