class MinStack {
public:
    stack<long long> St;
    stack<long long> minST;
    long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        St.push(val);
        if(min > val)
            min = val;
        minST.push(min);
    }
    
    void pop() {
        St.pop();
        minST.pop();
        if(minST.empty())
            min = LLONG_MAX;
        else
            min = minST.top();
            
    }
    
    int top() {
        return St.top();
    }
    
    int getMin() {
        return minST.top();
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