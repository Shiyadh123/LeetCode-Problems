class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int> a(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int cnt=0;
            auto x=lower_bound(potions.begin(),potions.end(),ceil(success/(double)spells[i]));
            a[i]=potions.size()-(x-potions.begin());
        }
        return a;
    }
};