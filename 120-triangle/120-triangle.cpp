class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1) return triangle[0][0];
        vector<int> curr(n);
        vector<int> prev(n);
        prev[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int top=INT_MAX,left=INT_MAX;
                if(j!=0) left=prev[j-1];
                if(j!=i) top=prev[j];
                curr[j]=min(top,left)+triangle[i][j];
            }
            prev=curr;
        }
        return *min_element(curr.begin(),curr.end());
    }
};