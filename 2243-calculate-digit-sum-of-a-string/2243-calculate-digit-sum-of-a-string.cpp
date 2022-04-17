class Solution {
public:
    string sum(string s){
        
        long long n=0;
        
        for(auto i:s){
            n+=(i-'0');
        }
        
        return to_string(n);

    }
    string digitSum(string s, int k) {
        
        int l=s.length();
        string temp;
        
        while(s.length()>k){
            
            int i=0;
            
            while(i<s.length()){
                
                if(i<s.length()){
                    temp=sum(s.substr(i,k));
                    s.replace(i,k,temp);
                }
                
                i+=temp.length();
            }
            
        }
        
        return s;
    }
};