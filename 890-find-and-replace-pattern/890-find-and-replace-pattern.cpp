class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int patLen=pattern.length();
        vector<string> res;
        for(auto word:words){
            if(word.length()!=pattern.length()) continue;
            vector<int> map1(26,-1);
            vector<int> map2(26,-1);
            int i=0;
            for(i=0;i<patLen;i++){
                if(map1[pattern[i]-'a']==-1&&map2[word[i]-'a']==-1) {map1[pattern[i]-'a']=word[i]-'a';map2[word[i]-'a']=pattern[i]-'a';}
                else{
                    if(map1[pattern[i]-'a']!=word[i]-'a'||map2[word[i]-'a']!=pattern[i]-'a') break;
                }
            }
            if(i==patLen) res.push_back(word);
        }
        return res;
    }
};