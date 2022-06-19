class Solution {
public:
    int minimumNumbers(int num, int k) {
        int a=0;
        if(num==0) return 0;
        if(k==0) return num%10?-1:1;
        while(num>=0){
            num-=k;
            a++;
            if(num%10==0&&num>=0) return a;
        }
        return -1;
    }
};