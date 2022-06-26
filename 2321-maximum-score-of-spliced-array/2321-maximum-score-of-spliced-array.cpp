class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
         
        vector<int> diff1(n);
        vector<int> diff2(n);
        for(int i=0;i<n;i++){
            diff1[i]=nums1[i]-nums2[i];
            diff2[i]=-nums1[i]+nums2[i];
        }
        int s1=0,s2=0;
        s1=accumulate(nums1.begin(),nums1.end(),s1);
        s2=accumulate(nums2.begin(),nums2.end(),s2);
        int sm1=0,sm2=0,max1=0,max2=0;
         for(int i=0;i<n;i++){
             sm1+=diff1[i];
             max1=max(max1,sm1);
             if(sm1<0) sm1=0;
             sm2+=diff2[i];
             max2=max(max2,sm2);
             if(sm2<0) sm2=0;
        }
        return max(s2+max1,s1+max2);
    }
};
