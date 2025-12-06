struct MoStack 
{
    stack<int> st1, st2;
    void Push(int n) 
    {
        st1.push(n);
        if (st2.empty() || st2.top() >= n)
            st2.push(n);
    }
    void Pop()
    {
        if (st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }
    int Max()
    {
        return st2.top();
    }

    int Top()
    {
        return st1.top();
    }
};
class MinStack {
public:
    MoStack st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.Push(val);
    }
    
    void pop() {
        st.Pop();
    }
    
    int top() {
        return st.Top();
    }
    
    int getMin() {
        return st.Max();
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