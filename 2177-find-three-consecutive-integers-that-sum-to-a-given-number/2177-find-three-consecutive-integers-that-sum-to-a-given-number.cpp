class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> nos;
        long long n;
        if((num-3)%3!=0) return  nos;
        n=(num-3)/3;
        nos.insert(nos.end(),{n,n+1,n+2});
        return nos;
    }
};