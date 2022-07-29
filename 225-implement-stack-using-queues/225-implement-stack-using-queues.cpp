class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
       int size=q.size();
        size--;
        while(size--) {
            q.push(q.front()); q.pop();
        }
        int x=q.front();
          q.pop();
        return x;
    }
    
    int top() {
        int size=q.size();
        size--;
        while(size--) {
            q.push(q.front()); q.pop();
        }
        int x=q.front();
        q.push(q.front()); q.pop();
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};