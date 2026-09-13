class MinStack {
public:
    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int mini = min(val, minSt.empty() ? val : minSt.top());
        minSt.push(mini);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
