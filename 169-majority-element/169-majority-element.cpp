class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,no=-1;
        for(int i=0;i<n;i++){
            if(cnt==0) {
                no=nums[i];
                cnt++;
            }else{
                cnt+=(no==nums[i])?1:-1;
            }
        }
        return no;
    }
};