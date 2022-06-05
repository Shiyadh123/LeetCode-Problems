class Solution {
public:

    bool isSafe(int row,int col,vector<string> board,int n,vector<bool> top,vector<bool> rightDia,vector<bool> leftDia){
       if(top[col]==1) return false;
       if(rightDia[col+row]==1) return false;
       if(leftDia[n+col-row]==1) return false;
       return true;
    }
    void fillRow(int i,int n,vector<string> board, vector<vector<string>> &ans,vector<bool> top,vector<bool> rightDia,vector<bool> leftDia){
        if(i>=n) {ans.push_back(board); return;}
        for(int j=0;j<n;j++){
            if(isSafe(i,j,board,n,top,rightDia,leftDia)){
                top[j]=1;
                rightDia[i+j]=1;
                leftDia[n+j-i]=1;
                board[i][j]='Q';
                fillRow(i+1,n,board,ans,top,rightDia,leftDia);
                board[i][j]='.';
                top[j]=0;
                rightDia[i+j]=0;
                leftDia[n+j-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        vector<bool> top(n,0);
        vector<bool> rightDia(2*n+1,0);
        vector<bool> leftDia(2*n+1,0);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        fillRow(0,n,board,ans,top,rightDia,leftDia);
        return ans;
    }
};