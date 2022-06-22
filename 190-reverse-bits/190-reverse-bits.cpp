class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s;
        int p=32;
        while(p--){
            int temp=n%2;
            s.push_back(temp+'0');
            n/=2;
        }
        // cout<<s;
        return stol(s,0,2);;
    }
};