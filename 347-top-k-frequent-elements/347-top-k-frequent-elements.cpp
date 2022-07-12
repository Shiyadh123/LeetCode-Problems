class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        
        vector<vector<int>> bucket(100001);
        for(auto i:mp){
            bucket[i.second].push_back(i.first);
        }

        vector<int> ans;
        for(int i=100000;i>=0;i--){
            if(k==0) break;
            if(!bucket[i].empty()){
                for(auto  j:bucket[i]){
                    if(k==0) break;
                    ans.push_back(j); k--;
                }
            }
        }
        return ans;
    }
};