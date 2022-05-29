class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
         int m=a.size();
         int n=a[0].size();
         bool flag=1;//row0col0 as col0 indicator
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(a[i][j]==0){
                    
                    if(j==0) flag=0;
                    else a[0][j]=0;
                    
                    a[i][0]=0;
                }
            }
        }
        
         for(int j=n-1;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                
                if(a[i][0]==0||(j==0&&flag==0)||(j!=0&&a[0][j]==0)){
                    a[i][j]=0;
                }
                
            }
        }
        return;
    }
};