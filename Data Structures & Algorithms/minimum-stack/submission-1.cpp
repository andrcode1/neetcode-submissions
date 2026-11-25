class MinStack {
public:
    std::stack<int> generalStack{};
    std::stack<int> minStack{};

    MinStack() {}
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push(val);
        } else if (val <= minStack.top()) {
            minStack.push(val);
        }

        generalStack.push(val);
    }
    
    void pop() {
        if (generalStack.top() == minStack.top()) {
            minStack.pop();
        }
        generalStack.pop();
    }
    
    int top() {
        return generalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
