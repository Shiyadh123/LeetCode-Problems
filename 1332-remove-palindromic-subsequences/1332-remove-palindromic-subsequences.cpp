class Solution {
public:
    bool isPali(string s){
        int l=s.length();
        int i=0,j=l-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.length()==0) return 0;
        if(isPali(s)) return 1;
        else return 2;
    }
};
