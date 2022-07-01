class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]>b[1];        
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int n=boxTypes.size(),ans=0;
        int i=0;
        while(i<n&&truckSize>0){
            if(boxTypes[i][0]<=truckSize){
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }else{
                ans+=(truckSize*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            i++;
        }
        return ans;
    }
};