class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top()); st.pop();
        }
        temp.push(x);
         while(!temp.empty()){
            st.push(temp.top()); temp.pop();
        }
        return;
    }
    
    int pop() {
        int s=st.top();
        st.pop();
        return s;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};