class Solution {
public:
    double mult(double x,int n){
        if(n==0) return 1;
        double temp=mult(x,n/2);
        if(n%2){
            return x*temp*temp;
        }else{
            return  temp*temp;
        }
    }
    
    double myPow(double x, int n) {
        double ans=1;
        if(n==0) return 1;
        if(n>0){
             for(int i=0;i<n;i++){
                return mult(x,n);
            }
        }else{
             for(int i=0;i<abs(n);i++){
                return mult(1/x,n);
             }
        }
        return ans;
    }
};