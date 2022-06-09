class Solution {
public:
    // vector<int> ans;
    // void fun(int i,vector<int> nums,vector<int> temp){
    //     if(i==nums.size()){
    //         if(temp.size()>ans.size()) ans=temp;
    //     }
    //     if(i==0||(temp[temp.size()-1]%nums[i])==0||(nums[i]%temp[temp.size()-1])==0){
    //         temp.push_back(nums[i]);
    //         fun(i+1,nums,temp);
    //         temp.pop_back();
    //     }
    //     fun(i+1,nums,temp);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prevInd(n);
        vector<int> ans;
        for(auto i=0;i<n;i++) prevInd[i]=i;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    dp[i]=max(1+dp[prev],dp[i]);
                    if(dp[i]==1+dp[prev]) prevInd[i]=prev;
                }
            }
        }
        int maxLen=0;
         for(auto i=0;i<n;i++) maxLen=max(maxLen,dp[i]);
        int i=n-1;
        while(i>=0&&dp[i]!=maxLen) i--;
        while(prevInd[i]!=i){
            ans.push_back(nums[i]);
            i=prevInd[i];
        }
                ans.push_back(nums[i]);
        return ans;
    }
};