class Solution {
public:
    vector<string> res;
    void gen(string s,int o,int c,int n){
        if(c==n){
            res.push_back(s);
        }
        if(o<n){
            s.push_back('(');
            gen(s,o+1,c,n);
            s.pop_back();
        }
        if(c<o){
             s.push_back(')');
            gen(s,o,c+1,n);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        gen("",0,0,n);
        return res;
    }
};