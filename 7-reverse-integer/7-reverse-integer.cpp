class Solution {
public:
    int reverse(int x) {
        int n=x,r,res=0;
        while(n!=0)
        {
            r=n%10;
            n=n/10;
            if(res>INT_MAX/10||res<INT_MIN/10)
                return 0;
            res=res*10+r;
        }
        return res;
    }
};