class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mpS,mpT;
        for(auto i:s) mpS[i]++;
        for(auto i:t) mpT[i]++;
        for(auto pr:mpS){
            if(pr.second!=mpT[pr.first]) return false;
        }
        return true;
    }
};