class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  grp;
        unordered_map<string,vector<int>> dict;
        for(auto i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            dict[temp].push_back(i);
        }
        for(auto i:dict){
            vector<string> temp;
            for(auto j:i.second){
                temp.push_back(strs[j]);
            }
            grp.push_back(temp);
        }
        return grp;
    }
};