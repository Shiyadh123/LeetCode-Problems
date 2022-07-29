class Solution {
public:
    bool isPossible(unordered_map<int ,int> mp,int n){
        if(mp.size()>=2&&mp.find(n)==mp.end()) return false;
        return true;
    }
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int ,int> mp;
        int left=0,right=0,len=0;
        while(right<n){
            while(!isPossible(mp,fruits[right])){
                left++;
                if(mp[fruits[left-1]]==1){
                    mp.erase(fruits[left-1]);
                }else{
                    mp[fruits[left-1]]--;
                }
            }
            mp[fruits[right]]++;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};