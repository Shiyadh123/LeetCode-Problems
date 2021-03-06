class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty()&&dq.front().second<=i-k) dq.pop_front();
            while(!dq.empty()&&dq.back().first<=nums[i]) dq.pop_back();
            dq.push_back({nums[i],i});
            if(i<k-1) continue;
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};
