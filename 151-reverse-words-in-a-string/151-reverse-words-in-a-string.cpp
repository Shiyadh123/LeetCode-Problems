class Solution {
public:
    string trimm(string s){
        string res="";
        bool isBegin=true;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(isBegin) continue;
                else if(i<n-1&&s[i+1]==' ') continue;
                else res.push_back(' ');
            }else{
                isBegin=false;
                res.push_back(s[i]);
            }
        }
        if(res.back()==' ') res.pop_back();
        return res;
    }
    string reverseWords(string s) {
        s=trimm(s);
        reverse(s.begin(),s.end());
        int begin=0,end;
        for(int i=0;i<=s.length();i++){
            if(i==s.length()||s[i]==' '){
                reverse(s.begin()+begin,s.begin()+i);
                begin=i+1;
            }
        }
        return s;
    }
};