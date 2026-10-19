class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.size()){
            val = (val < min_stack.top()) ? val : min_stack.top();
            min_stack.push(val);
        }
        else
            min_stack.push(val);
    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }

    private:
    stack<int> main_stack;
    stack<int> min_stack;
};
