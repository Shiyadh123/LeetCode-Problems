class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int ,int> mp;
        int n=s.length();
        int m=t.size();
        if(n!=m)
            return false;
        for(auto i:s)
            mp[i-'a']++;
        for(auto i:t)
            mp[i-'a']--;
        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0)
                return false;
        }
        return true;
    }
};