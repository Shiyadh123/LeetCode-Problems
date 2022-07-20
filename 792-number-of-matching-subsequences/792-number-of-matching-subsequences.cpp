class Solution {
public:
    bool isSub(string word,vector<vector<int>> &index){
        int currInd=-1;
        for(auto i:word){
            auto it=upper_bound(index[i-'a'].begin(),index[i-'a'].end(),currInd);
            if(it!=index[i-'a'].end()){
                currInd=index[i-'a'][it-index[i-'a'].begin()]; 
            }else {
                return false;
            }
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(26);
        int cnt=0;
        for(int i=0;i<s.length();i++) index[s[i]-'a'].push_back(i);
        for(auto i:words){
            if(isSub(i,index)) cnt++;
        }
        return cnt;
    }
};