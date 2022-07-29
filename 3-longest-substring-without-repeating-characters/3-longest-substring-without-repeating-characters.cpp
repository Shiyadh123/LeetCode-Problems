class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0,right=0,len=0;
        unordered_map<char,int> mp;

        while(right<n){
            if(mp.find(s[right])!=mp.end()&&(mp[s[right]]>=left)) left=mp[s[right]]+1;
            len=max(len,right-left+1);
            mp[s[right]]=right;
            right++;
        }
        return len;
    }
};