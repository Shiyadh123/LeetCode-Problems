class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
           int n=nums.size();
           unordered_set<int> st;
           for(auto i:nums) st.insert(i);
           int maxLen=0;
           for(auto i:st){
                if(st.find(i-1)==st.end()){
                    int curr=i;
                    while(st.find(curr)!=st.end()){
                        maxLen=max(maxLen,curr-i+1);
                        curr=curr+1;
                    }
                }
           }
           return maxLen;
    }
};