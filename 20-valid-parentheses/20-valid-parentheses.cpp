class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(st.empty()||i=='('||i=='{'||i=='['){
                st.push(i);
            }else if(i==')'){
                if(st.top()=='(') st.pop();
                else st.push(i);
            }else if(i=='}'){
                if(st.top()=='{') st.pop();
                else st.push(i);
            }else {
                if(st.top()=='[') st.pop();
                else st.push(i);
            }
        }
        return st.empty();
    }
};