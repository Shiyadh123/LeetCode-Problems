class Solution {
public:
    void fillForN(vector<vector<int>>& ans,int startVal,int p,int q,int n){
        
        if(n<=0) return ;
        if(n==1){
            ans[p][q]=startVal;
            return;
        }
        
        for(int i=0;i<n;i++){
            ans[p][q++]=startVal;
            startVal++;
        }
        q--;
        
        for(int i=1;i<n;i++){
            ans[++p][q]=startVal;
            startVal++;
        }
        
        for(int i=1;i<n;i++){
            ans[p][--q]=startVal;
            startVal++;
        }
        
        for(int i=2;i<n;i++){
            ans[--p][q]=startVal;
            startVal++;
        }
        
        fillForN(ans,startVal,p,q+1,n-2);
    }
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int> (n,0));
        
        fillForN(ans,1,0,0,n);
        
        return ans;
    }
};