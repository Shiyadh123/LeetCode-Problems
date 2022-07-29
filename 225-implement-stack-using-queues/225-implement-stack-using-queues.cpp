class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(q.size()>1) {
            temp.push(q.front()); q.pop();
        }
        int x=q.front();
        q.pop();
        while(temp.size()>0) {
            q.push(temp.front()); temp.pop();
        }
        return x;
    }
    
    int top() {
        queue<int> temp;
        while(q.size()>1) {
            temp.push(q.front()); q.pop();
        }
        int x=q.front();
        temp.push(q.front()); q.pop();
        while(temp.size()>0) {
            q.push(temp.front()); temp.pop();
        }
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};