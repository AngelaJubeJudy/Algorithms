class MinStack {
private:
    stack<int> preMin;
    stack<int> st;

public:
    /** initialize your data structure here. */
    MinStack() {
        preMin.push(INT_MAX);
    }
    
    void push(int val) {
        preMin.push(min(val,  preMin.top()));
        st.push(val);
    }
    
    void pop() {
        preMin.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return preMin.top();
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */