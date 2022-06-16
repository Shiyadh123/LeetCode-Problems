class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n=nums.size();
         int cnt1=0,cnt2=0,n1=(1e9)+1,n2=(1e9)+1;
        for(int i=0;i<n;i++){
            if(nums[i]==n1){
                cnt1++;
            }else if(nums[i]==n2){
                cnt2++;
            }else if(cnt1==0){
                n1=nums[i];cnt1++;
            }else if(cnt2==0){
                n2=nums[i];cnt2++;
            }else{
                cnt1--;cnt2--;
            }
        }
        int reqCnt=n/3;
        cnt1=0;cnt2=0;
        // cout<<n1<<cnt1<<" "<<n2<<cnt2;
        for(auto i:nums){
            if(i==n1) cnt1++;
            if(i==n2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>reqCnt) ans.push_back(n1);
        if(cnt2>reqCnt) ans.push_back(n2);
        return ans;
    }
};