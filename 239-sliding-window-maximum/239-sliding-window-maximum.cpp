class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>  pq;
        int n=nums.size();
        vector<int> ans;
        int i=1,j=k;//left,right pointes
        while(k--){
            pq.push({nums[k],k});
        }
        ans.push_back(pq.top().first);
        while(i<n&&j<n){
            pq.push({nums[j],j});
            while(pq.top().second<i) pq.pop();
            ans.push_back(pq.top().first);
            i++;j++;
        }
        return ans;
    }
};