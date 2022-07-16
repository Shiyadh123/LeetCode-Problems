class Solution {
public:
    int findIndex(vector<int>& nums, int tar,int flag){
        int n=nums.size(); 
        if(n==0) return -1;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(flag==1){
                if(nums[mid]>=tar) hi=mid-1;
                else lo=mid+1;
            }else{
                if(nums[mid]<=tar) lo=mid+1;
                else hi=mid-1;
            }
        }
        if(flag==1){
            if(lo==n||nums[lo]!=tar) return -1;
            else return lo;
        }else{
            if(hi==-1||nums[hi]!=tar) return -1;
            else return hi;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0]=findIndex(nums,target,1);
        ans[1]=findIndex(nums,target,2);
        return ans;
    }
};