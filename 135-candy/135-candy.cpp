class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        int ans=0;
        vector<int> need(n,1);
         for(int j=1;j<n;j++){
          if(ratings[j]>ratings[j-1]) need[j]=need[j-1]+1;
        }
         for(int j=n-1;j>=1;j--){
          if(ratings[j]<ratings[j-1]) need[j-1]=max(need[j-1],need[j]+1);
        }
        for(auto i:need) ans+=i;
        return ans;
    }
};