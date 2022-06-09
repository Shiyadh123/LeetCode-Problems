class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi){
            switch(a[mid]){
                case 0: swap(a[lo],a[mid]);mid++;lo++;break;
                case 1: mid++;break;
                case 2: swap(a[hi],a[mid]);hi--;break;
            }
        }return;
    }
};