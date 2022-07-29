class Solution {
public:
    bool isPossible(vector<int> map,int len ,int k,char ch){
        int maxCnt=0;
        map[ch-'A']++;
        for(auto i:map) maxCnt=max(maxCnt,i);
        return len-maxCnt<=k;
    }
    int characterReplacement(string s, int k) {
        int l=s.length();
        int left=0,right=0,len=0;
        vector<int> map(26,0);
        while(right<l){
            while(!isPossible(map,right-left+1,k,s[right])){
                left++;
                map[s[left-1]-'A']--;
            }
            map[s[right]-'A']++;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};