class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        if(stones.size()==1) return stones[0];
        
        priority_queue<int> pq;
        for(auto i:stones){
            pq.push(i);
        }

        while(pq.size()>1){
            
            int largest=pq.top();
            pq.pop();
            int secondLargest=pq.top();
            pq.pop();
            
            if(largest!=secondLargest){
                pq.push(largest-secondLargest);
            }
            
        }
        return !pq.empty()?pq.top():0;
    }
};