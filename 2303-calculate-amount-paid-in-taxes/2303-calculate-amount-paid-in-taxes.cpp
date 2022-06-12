class Solution {
public:
    double calculateTax(vector<vector<int>>& a, int income) {
        int n=a.size();
        double sm=0;
         for(int i=0;i<n;i++){
            int bp=min(a[i][0],income);
            sm+=(0.01*(bp-(i==0?0:a[i-1][0]))*a[i][1]);
            if(bp==income) break;
        }
        return sm;
    }
};