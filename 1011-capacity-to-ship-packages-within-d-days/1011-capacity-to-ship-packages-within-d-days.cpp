class Solution {
public:
    int noOfDays(int cap,vector<int>& weights){
        int cnt=0;
        int currWt=0; int n=weights.size();
        for(int i=0;i<n;i++){
            if(currWt+weights[i]>cap){
                cnt++;
                currWt=weights[i];
            }else{
                currWt+=weights[i];
            }
        }
        return 1+cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int minCap=*max_element(weights.begin(),weights.end());
        int maxCap=0;
        maxCap=accumulate(weights.begin(),weights.end(),maxCap);
        while(minCap<=maxCap){
            int  currCap=minCap+(maxCap-minCap)/2;
            int currDays=noOfDays(currCap,weights);
            if(currDays<=days){
                maxCap=currCap-1;
            }else{
                minCap=currCap+1;
            }
        }
        return  minCap;
    }
};
