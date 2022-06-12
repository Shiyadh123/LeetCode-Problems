class Solution {
public:
    bool strongPasswordCheckerII(string a) {
        int l=a.length();
        if(l<8) return false;
        int u=0,lo=0,dig=0,sp=0,adj=0;
       for(int i=0;i<l;i++){
            if(a[i]>='A'&&a[i]<='Z') u++;
            if(a[i]>='a'&&a[i]<='z') lo++;
            if(a[i]>='0'&&a[i]<='9') dig++;
            for(auto j:"!@#$%^&*()-+") if(a[i]==j) sp++;
            if(i>0){
                if(a[i]==a[i-1]) adj++;
            }
         }
         if(u==0||lo==0||dig==0||sp==0||adj!=0) return false;
         return true;
    }
};