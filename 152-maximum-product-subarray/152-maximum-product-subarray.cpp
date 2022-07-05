class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n=nums.size();
          if(n==1) return nums[0];
          vector<int> maxi(n);  
          vector<int> mini(n);  
          maxi[0]=nums[0]; mini[0]=nums[0];
        for(int i=1;i<n;i++){
            maxi[i]=std::max({nums[i],nums[i]*maxi[i-1],nums[i]*mini[i-1]});
            mini[i]=std::min({nums[i],nums[i]*maxi[i-1],nums[i]*mini[i-1]});
        }
        return *max_element(maxi.begin(),maxi.end());
    }
};