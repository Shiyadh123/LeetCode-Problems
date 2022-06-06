class Solution {
public:
    int maxProfit(vector<int>& price) {
        if(price.size()==0)
            return 0;
        int mini=price[0];
        int maxiPro=0;
        for(int i=1;i<price.size();i++){
            int profit=price[i]-mini;
            maxiPro=max(maxiPro,profit);
            mini=min(mini,price[i]);
        }
        return maxiPro;
    }
};