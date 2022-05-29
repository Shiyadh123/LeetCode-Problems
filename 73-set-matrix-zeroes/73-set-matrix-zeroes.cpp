class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
         int m=a.size();
         int n=a[0].size();
         bool row0=1,col0=1;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(a[i][j]==0){
                    a[i][0]=0;
                    a[0][j]=0;
                    if(i==0) row0=0;
                    if(j==0) col0=0;
                }

            }
        }
        
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(a[i][0]==0||a[0][j]==0){
                    a[i][j]=0;
                }

            }
        }
        if(!col0){
            for(int i=1;i<m;i++){
                a[i][0]=0;
            }
        }
        if(!row0){
            for(int j=1;j<n;j++){
                a[0][j]=0;
            }
        }
        return;
    }
};