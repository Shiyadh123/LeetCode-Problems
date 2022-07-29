class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,minLen=INT_MAX,left=0,right=0,n=nums.size();
        // sum=nums[0];
        // while(left<n&&right<n){
        //     if(sum<target){
        //         right++; sum+=(right<n?nums[right]:0);
        //     }else{
        //         minLen=min(minLen,right-left+1);
        //         left++;  sum-=(left<n?nums[left-1]:0);
        //     }
        // }
        // return (minLen==INT_MAX?0:minLen);
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<n;i++){
            int tar=prefix[i]-target;
            if(tar<0) continue;
            int lo=0,hi=i-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(prefix[mid]>tar) hi=mid-1;
                else lo=mid+1;
            }
            // // cout<<hi<<" "<<lo<<" ";
            minLen=min(minLen,i-hi);
            // cout<<minLen<<"  ";
        }
        return minLen==INT_MAX?0:minLen;
    }
};