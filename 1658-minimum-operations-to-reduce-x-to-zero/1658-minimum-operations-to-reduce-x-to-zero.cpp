class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sumOfNums=0;
        for(int i=0;i<n;i++) sumOfNums+=nums[i];

        unordered_map<int,int> mp;
        mp[0]=-1;
        int maxLen=0;
        int k=sumOfNums-x;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(mp.find(currSum-k)!=mp.end()){
                maxLen=max(maxLen,i-mp[currSum-k]);
            }
            if(mp.find(currSum)==mp.end()) mp[currSum]=i;
        }
        return (maxLen==0&&k!=0)?-1:(n-maxLen);
    }
};