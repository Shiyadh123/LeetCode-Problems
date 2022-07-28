class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length()) return ans;
        vector<int> curr(26,0),pMap(26,0);
        int m=s.length(),n=p.length();
        int i=0;
        while(i<n) {
            curr[s[i]-'a']++; pMap[p[i]-'a']++; i++;
        }
        if(curr==pMap) ans.push_back(0);
        i=0;
        while(i<(m-n)){
            i++;
            curr[s[i+n-1]-'a']++;
            curr[s[i-1]-'a']--;
            if(curr==pMap) ans.push_back(i);
            
        }
        return ans;
    }
};