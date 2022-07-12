class Solution {
public:
    static bool comp(pair<int,int> p,pair<int,int> q){
        return p.second>q.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};