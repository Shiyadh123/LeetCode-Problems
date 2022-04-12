class Solution {
public:
    int m,n;
    bool isValid(int i,int j){
        if(i<0||j<0||i>=m||j>=n) return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m=board.size();
        n=board[0].size();
        vector<int> dx={-1,0,1};
        vector<vector<int>> temp(board);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbourSum=0;
                for(auto p:dx){
                    for(auto q:dx){
                        if(p!=0||q!=0){
                            neighbourSum+=(isValid(i+p,j+q)?temp[i+p][j+q]:0);
                        }
                    }
                }
                if(neighbourSum<2) board[i][j]=0;
                else if(neighbourSum==2)  board[i][j]=temp[i][j];
                else if(neighbourSum==3) board[i][j]=1;
                else board[i][j]=0;
            }
        }
        return;
    }
};