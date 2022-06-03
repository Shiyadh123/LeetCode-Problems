class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        mat.resize(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int top=(i==0)?0:mat[i-1][j];
                int left=(j==0)?0:mat[i][j-1];
                int corner=(i==0||j==0)?0:mat[i-1][j-1];
                int current=matrix[i][j];
                mat[i][j]=top+left-corner+current;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top=(row1==0)?0:mat[row1-1][col2];
        int left=(col1==0)?0:mat[row2][col1-1];
        int cornerEnd=mat[row2][col2];
        int cornerBegin=(col1==0||row1==0)?0:mat[row1-1][col1-1];
        return cornerEnd-top-left+cornerBegin;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */