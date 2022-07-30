class MyQueue {
public:
    stack<int> ip,op;
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
        return;
    }
    
    int pop() {
        int s;
        if(op.empty()){
            ipToOp();
        } 
        s=op.top(); op.pop();
        return s;
    }
    
    int peek() {
        int s;
        if(op.empty()){
            ipToOp();
        } 
        s=op.top(); 
        return s;
    }
    
    bool empty() {
        return ip.empty()&&op.empty();
    }
    void ipToOp(){
        while(!ip.empty()){
            op.push(ip.top()); ip.pop();
        }
    }
};
