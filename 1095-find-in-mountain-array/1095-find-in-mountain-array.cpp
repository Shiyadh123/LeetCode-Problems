class Solution {
public:
        int findInMountainArray(int tar, MountainArray &mountainArr) {
        int n=mountainArr.length();
        //Find PEAK
        int lo=0,hi=n-1,peak,left=-1,right=-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) lo=mid+1;
            else hi=mid;
        }
        peak=lo;
        //LEFT search
        lo=0,hi=peak;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<tar) lo=mid+1;
            else if(mountainArr.get(mid)>tar)hi=mid-1;
            else {left=mid;break;}
        }
        //RIGHT search
        lo=peak,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<tar) hi=mid-1;
            else if(mountainArr.get(mid)>tar) lo=mid+1;
            else {right=mid;break;}
        }
        return (left==-1)?right:left;
    }
};