class Solution {
public:
    bool isValid(vector<int> sMap,vector<int> tMap){
        for(auto i=0;i<128;i++){
            if(sMap[i]<tMap[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>  tMap(128,0),sMap(128,0),indices(2,-1);
        int n=s.length(),m=t.length(),len=INT_MAX;
        for(auto i:t) tMap[i]++;
        int left=0,right=0;
        while(right<n){
            sMap[s[right]]++;
            while(isValid(sMap,tMap)){
                if(right-left+1<len) {len=right-left+1;
                indices={left,right};}
                left++; sMap[s[left-1]]--;
            }
            right++;
        }
        return len==INT_MAX?"":s.substr(indices[0],indices[1]-indices[0]+1); 
    }
};