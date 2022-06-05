class Solution {
public:
    bool isSafe(int row,int col,int n,vector<bool> top, vector<bool> rightDia, vector<bool> leftDia){
        if(top[col]==1) return false;
        if(rightDia[row+col]==1) return false;
        if(leftDia[n+col-row]==1) return false;
        return true;
    }
    int fun(int i,int n,vector<string> board,vector<bool> top, vector<bool> rightDia, vector<bool> leftDia){
        if(i==n) return 1;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(isSafe(i,j,n,top,rightDia,leftDia)){
                top[j]=1;
                rightDia[j+i]=1;
                leftDia[n+j-i]=1;
                board[i][j]='Q';
                cnt+=fun(i+1,n,board,top,rightDia,leftDia);
                board[i][j]='.';
                top[j]=0;
                rightDia[j+i]=0;
                leftDia[n+j-i]=0;
            }
        }
        return cnt;
    }

    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        vector<bool> top(n,0);
        vector<bool> rightDia(2*n,0);
        vector<bool> leftDia(2*n,0);
        return fun(0,n,board,top,rightDia,leftDia);
    }
};