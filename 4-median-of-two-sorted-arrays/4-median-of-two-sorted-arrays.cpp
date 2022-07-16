class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int lo=0,hi=n1;
        int l1,l2,r1,r2;
        while(lo<=hi){
            int cut1=lo+(hi-lo)/2;
            int cut2=((n1+n2+1)/2)-cut1;
                l1=cut1>0?nums1[cut1-1]:INT_MIN;
                l2=cut2>0?nums2[cut2-1]:INT_MIN;
                r1=cut1<n1?nums1[cut1]:INT_MAX;
                r2=cut2<n2?nums2[cut2]:INT_MAX;
            
            if(l1>r2) hi=cut1-1;
            else if(l2>r1) lo=cut1+1;
            else break;

        }
        if((n1+n2)%2) return max(l1,l2);
        else return ((double)max(l1,l2)+min(r1,r2))/2;
    }
};