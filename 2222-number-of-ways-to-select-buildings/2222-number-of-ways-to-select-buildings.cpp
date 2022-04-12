class Solution {
public:
    int n;
    long long  subNumberOfWays(string s,char ch){
        int sum=0,currSum=0;
        long long ans=0;
        for(auto i:s) if(i!=ch) sum++;
        for(auto i:s){
            if(i==ch)
                ans+=(currSum*(sum-currSum));
            else
                currSum++;
        }
        return ans;
    }
    long long numberOfWays(string a) {
        n=a.size();
        
        return subNumberOfWays(a,'0')+subNumberOfWays(a,'1');
    }
};