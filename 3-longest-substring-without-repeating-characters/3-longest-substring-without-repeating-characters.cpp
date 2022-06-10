class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=s.length();
        int maxLen=0;
        for(int i=0;i<l;i++){
            int len=0;
            unordered_map<char,int> mp;
            for(int j=i;j<l;j++){
                if(mp.find(s[j])!=mp.end()){
                    break;
                }else{
                    mp[s[j]]++;
                    len++;
                }
            }
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};