class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int ans=0;
        for(auto i:nums) st.insert(i);
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int cnt=1;
                int temp=nums[i];
                while(st.find(temp+1)!=st.end()) {
                    cnt++;
                    temp+=1;
                }
                ans=max(ans,cnt);
            }    
        }
        return ans;
    }
};