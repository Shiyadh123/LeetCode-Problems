class Solution {
public:
    string normalize(string a){
        unordered_map<char,char> mp;
        char curr='a';
        for(auto i:a){
            if(!mp[i]) mp[i]=curr;
            curr++;
        }
        for(int i=0;i<a.length();i++){
            a[i]=mp[a[i]];
        }
        return a;
    }
    bool isIsomorphic(string s, string t) {
        return normalize(s)==normalize(t);
    }
};