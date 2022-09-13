class MyStack {
public:
    int t;
    stack<int> Q;
    MyStack() {
        t = 0;
    }
    
    void push(int x) {
        Q.push(x);
        t = x;
    }
    
    int pop() {
        if(Q.empty())
            return 0;
        int x;
        x = Q.top();
        Q.pop();
        return x;
    }
    
    int top() {
        return Q.top();
    }
    
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */