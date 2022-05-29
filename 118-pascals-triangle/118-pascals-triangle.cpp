class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        
        vector<int> a(1,1);
        v.push_back(a);
        
        if(numRows==1)
        {   
            return v;
        }
        
        for(int i=1;i<numRows;i++){
            vector<int> tmp;
            
            for(int j=0;j<=i;j++){
                if(j==0||j==i) tmp.push_back(1);
                else tmp.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            
            v.push_back(tmp);
        }
        return v;
        
    }
};