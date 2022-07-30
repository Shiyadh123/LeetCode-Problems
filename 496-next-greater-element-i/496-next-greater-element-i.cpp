class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> nge;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums2[i]>st.top().first){
                nge[st.top().first]=nums2[i];
                st.pop();
            }
            st.push({nums2[i],i});
        }
        vector<int> res;
        for(auto i:nums1){
            res.push_back(nge.find(i)!=nge.end()?nge[i]:-1);
        }
        return res;
    }
};