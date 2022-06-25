class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string s="";
        long long grpSize=1;
        vector<int> nos;
        for(int i=1;i<=n;i++){
            grpSize*=i;
            nos.push_back(i);
        }
        while(nos.size()!=0){
            grpSize=grpSize/nos.size();
            int grp=k/grpSize;
            k=k%grpSize;
            s+=('0'+nos[grp]);
            nos.erase( nos.begin()+grp );
            // cout<<grpSize<<" "<<grp<<" "<<k<<endl;
        }
        return s;
    }
};