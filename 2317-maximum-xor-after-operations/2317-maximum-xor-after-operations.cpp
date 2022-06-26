class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n=nums.size();
        vector<int> bits(32,0);
        for(int i=0;i<n;i++){
             for(int j=0;j<32;j++){
                int mask=1<<j;
                if(nums[i]&mask) bits[j]++;
             }
        }
        int ans=0;
        for(int j=0;j<32;j++){
                if(bits[j]) ans+=pow(2,j);
        }
        return ans;
    }
};