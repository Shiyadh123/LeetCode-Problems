class Solution {
public:
    bool isAbc(stack<char> st){
        string t="ba";
        int  i=0;
        while(i<3&&!st.empty()&&st.top()==t[i]){
            st.pop();
            i++;
        }
        return i==2;
    }
    void eraseAbc(stack<char>& st){
        int n=2;
        while(n--){
            st.pop();
        }
        return ;
    }
    bool isValid(string s) {
        int l=s.length();
        stack<char> st;
        for(int i=0;i<l;i++){
            if(s[i]=='c'){
                if(isAbc(st)){
                eraseAbc(st);
            }else{
                return false;
            }
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};