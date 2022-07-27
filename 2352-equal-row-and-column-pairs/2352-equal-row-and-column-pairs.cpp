class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),cnt=0; 
        unordered_map<string,int> rows,cols;
        for(int i=0;i<n;i++){
            string strCol="",strRow="";
            for(int j=0;j<n;j++){
               strCol+=( to_string(grid[i][j]));  strCol.push_back('-');
                strRow+=( to_string(grid[j][i]));   strRow.push_back('-');
            }
            rows[strRow]++;
            cols[strCol]++;
        }
        for(auto i:rows){
            cnt+=(cols[i.first]*i.second);
        }
        return cnt;
    }
};