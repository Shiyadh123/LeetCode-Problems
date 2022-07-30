class Solution {
public:
    vector<int> freqCounter(string s){
            vector<int> ans(26,0);
            for(auto i:s){
                ans[i-'a']++;
            }
            return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> maxFreq(26,0);
        for(auto str:words2){
            vector<int> temp=freqCounter(str);
            for(int i=0;i<26;i++){
                maxFreq[i]=max(maxFreq[i],temp[i]);
            }
        }
        for(int i=0;i<words1.size();i++){
            vector<int> temp=freqCounter(words1[i]);
            int j;
            for(j=0;j<26;j++){
                if(temp[j]<maxFreq[j]) break;
            }
            if(j==26) res.push_back(words1[i]);
        }
        return res;
    }
};