class Solution {
public:
    int getStateFromString(string s){
        int state=0;
        for(auto ch:s){
            int ind=ch-'a';
            state=state|(1<<ind);
        }
        return state;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> state(n);
        int len=0;
        for(int i=0;i<n;i++){
            state[i]=getStateFromString(words[i]);
           
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string a=words[i];
                string b=words[j];
                int lenA=a.length(),lenB=b.length();
                 // cout<<(state[i]&state[j])<<" ";
                if((state[i]&state[j])==0)
                 len=(lenA*lenB)>len?(lenB*lenA):len;
            }
        }
        return len;
    }
};