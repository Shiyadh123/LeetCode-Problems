class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int toFind=-nums[i];
            int left=i+1,right=n-1;
            if(toFind<0) break;//no neg nos to the right anymore
           
            while(left<right){
                if(nums[left]+nums[right]>toFind) right--;
                else if(nums[left]+nums[right]<toFind) left++;  
                else{
                    vector<int> triplet={nums[i],nums[left],nums[right]};
                    ans.push_back(triplet);
                    while(left<right&&nums[left]==triplet[1])  left++;
                    while(left<right&&nums[right]==triplet[2]) right--;
                }              
            }

            while(i+1<n&&nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};