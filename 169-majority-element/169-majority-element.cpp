class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt,no;
        if(n==0) return 0;
        no=nums[0];
        cnt=1;
        for(int i=1;i<n;i++){
            if(no==nums[i]) cnt++;
            else{
                if(cnt!=0) cnt--;
                else {no=nums[i];cnt++;}
                }
        }
        return no;
    }
};