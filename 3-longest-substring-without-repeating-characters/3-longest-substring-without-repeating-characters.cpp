class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0,right=0,len=0;
        unordered_set<char> st;

        while(right<n){
            while(st.count(s[right])){ left++; st.erase(s[left-1]); }
            st.insert(s[right]);
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};