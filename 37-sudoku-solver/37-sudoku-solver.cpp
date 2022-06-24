class Solution {
public:
bool isPossible(vector<vector<char>> board,int i,int j,char c){
    for(int p=0;p<9;p++){
        if(board[i][p]==c) return false;
        if(board[p][j]==c) return false;
    }
    int colStart=(j/3)*3;
    int rowStart=(i/3)*3;
    for(int p=0;p<9;p++){
                if(board[rowStart+(p/3)][colStart+(p%3)]==c) return false;
    }
    return true;
}
    bool solve(vector<vector<char>>& board){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isPossible(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};