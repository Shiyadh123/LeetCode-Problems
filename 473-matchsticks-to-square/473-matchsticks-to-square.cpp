class Solution {
public:
    bool helper(vector<int>& matchsticks,int arr[],int ind,int s){
        int n=matchsticks.size();
        if(ind==n){
            for(int i=1;i<4;i++){
                if(arr[i-1]!=arr[i]) return false;
            }
            return true;
        }
        for(int i=0;i<4;i++){
            if(ind==0){
                arr[i]+=matchsticks[ind];
                if(arr[i]<=(float)s/4) if(helper(matchsticks,arr,ind+1,s)) return true;
                arr[i]-=matchsticks[ind];
            }else{
                arr[i]+=matchsticks[ind];
                if(arr[i]<=(float)s/4) if(helper(matchsticks,arr,ind+1,s)) return true;
                arr[i]-=matchsticks[ind];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int arr[]={0,0,0,0};
        int s=0;
        sort(matchsticks.begin(),matchsticks.end(),greater<>());
        s=accumulate(matchsticks.begin(),matchsticks.end(),s);
        return helper(matchsticks,arr,0,s);
    }
};