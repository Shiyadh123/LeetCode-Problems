class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
         sort(horizontalCuts.begin(),horizontalCuts.end());
         sort(verticalCuts.begin(),verticalCuts.end());
         horizontalCuts.insert(horizontalCuts.begin(),0);
         verticalCuts.insert(verticalCuts.begin(),0);
         verticalCuts.push_back(w);
         horizontalCuts.push_back(h);
         long long  maxH=0,maxW=0;
        for(int i=0;i<verticalCuts.size()-1;i++){
            verticalCuts[i]=verticalCuts[i+1]-verticalCuts[i];
            maxH=max(maxH,(long long )verticalCuts[i]);
        }
        for(int i=0;i<horizontalCuts.size()-1;i++){
            horizontalCuts[i]=horizontalCuts[i+1]-horizontalCuts[i];
            maxW=max(maxW,(long long )horizontalCuts[i]);
        }
        return (maxH*maxW)%(MOD);
    }
};