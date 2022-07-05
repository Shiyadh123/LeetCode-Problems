class Solution {
public:
    int longestSubsequence(string s, int k) {
         long long l=s.length();
         long long i=l-1;
         long long suff=0;
         long long len=0;
         long long pow=1;
        int c=0;
        while(i>=0&&suff+pow<=k){
            ++c;
            if(s[i]=='1'){suff+=(pow);}
            if(suff>k) break;
            i--; pow=pow<<1;
        }
        // cout<<i<<" ";
        len+=c;
        for(int j=0;j<=i;j++){
             if(s[j]=='0') len++;
        }
        return (int)len;
    }
};