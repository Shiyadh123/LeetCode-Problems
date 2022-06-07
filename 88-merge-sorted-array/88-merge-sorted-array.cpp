class Solution {
public:
    void reorder ( vector<int>& nums2){
        int n=nums2.size();
        if (n==1) return;
        for(auto i=0;i<n-1;i++){
            if(nums2[i]>nums2[i+1]) swap(nums2[i],nums2[i+1]);
        }
        return;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                reorder(nums2);
            }
            // for(auto it:nums1) cout<<it<<" ";
            i++;
            // cout<<endl<<i<<" "<<j<<endl;
        }
        for(int p=0;p<n;p++){
            nums1[p+m]=nums2[p];
        }
        return;
    }
};
