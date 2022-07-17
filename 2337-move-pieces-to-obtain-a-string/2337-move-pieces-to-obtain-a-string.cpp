class Solution {
public:
    bool canChange(string start, string target) {
        int l=start.length();
        queue<pair<char,int>> q1;
        queue<pair<char,int>> q2;
        for(int i=0;i<l;i++){
            if(start[i]!='_') q1.push({start[i],i});
            if(target[i]!='_') q2.push({target[i],i});
        }
        if(q1.size()!=q2.size()) return false;
        while(!q1.empty()&& !q2.empty()){
            pair<char,int> a=q1.front(); q1.pop();
            pair<char,int> b=q2.front(); q2.pop();
            if(a.first!=b.first) return false;
            if(a.first=='L'&&a.second<b.second) return false;
            if(a.first=='R'&&a.second>b.second) return false;
        }
        return true;
    }
};