class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        int i=row-1,j=col+1;
        while(i>=0&&j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        i=row-1,j=col-1;
        while(i>=0&&j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        return true;
    }
    void fillRow(int i,int n,vector<string> board, vector<vector<string>> &ans){
        // cout<<i<<" ";
        // cout<<i<<" "<<board[i-1]<<endl;
        if(i>=n) {ans.push_back(board); return;}
        for(int j=0;j<n;j++){
            if(isSafe(i,j,board,n)){
                board[i][j]='Q';
                fillRow(i+1,n,board,ans);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        fillRow(0,n,board,ans);
        return ans;
    }
};