class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> mergedInt;
        if(n==0) intervals.push_back(newInterval);
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=newInterval[0]) {intervals.insert(intervals.begin()+i,newInterval);break;}
            if(i==n-1) intervals.push_back(newInterval);
        }
        if(intervals.size()==1) return intervals;
        vector<int> curr=intervals[0];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]<=curr[1]){
                curr[1]=max(intervals[i][1],curr[1]);
                i++;
            }else{
                mergedInt.push_back(curr);
                curr=intervals[i];
                i++;
            }
        }
        mergedInt.push_back(curr);
        return mergedInt;
    }
};
