class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> curr=intervals[0];
        int i=1;
        while(i<intervals.size()){
            vector<int> next=intervals[i];
            if(next[0]<=curr[1]){
                curr[1]=max(curr[1],next[1]);
                i++;
            }else{
                ans.push_back(curr);
                curr=intervals[i];
                i++;
            }
        }
        ans.push_back(curr);
        return ans;
    }
};