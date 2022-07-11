class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i:stones) pq.push(i);
        while(pq.size()>1){
            int a=pq.top();pq.pop();
            int b=pq.top();pq.pop();
            if(a!=b){
                pq.push(abs(b-a));
            } 
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }
};