class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        int m=operations.size();
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<m;i++){
            int ind=mp[operations[i][0]];
            nums[ind]=operations[i][1];
            mp.erase(operations[i][0]);
            mp[operations[i][1]]=ind;
        }
        return nums;
    }
};