class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long encoded;
        if(min_stack.size()){
            //If val is larger, encoded > 0, so min will
            //stay same. Encoded < 0 means, val is less than
            //the current min, so update the min.
            encoded = long(val) - long(current_min);
            current_min = min(current_min, val);
        }
        else{ //Only for the first push
            current_min = val;
            encoded = val - current_min;
        }
        // cout<<"Pushed: "<<"val: "<<val<<" "<<" Encoded: "<<encoded<<
        // " current min: "<<current_min<<"\n";
        min_stack.push(encoded);
    }
    
    void pop() {
        if(min_stack.size()){
            if(min_stack.top() < 0){//The min was updated for this case.
                //
                int encoded = min_stack.top();
                min_stack.pop();
                //Take a look at how we calculated the encoded
                //and handled the current min updating when val
                //was less than current min!
                int prev_min = current_min - encoded;
                current_min = prev_min;
            }
            else{
                min_stack.pop();
            }
        }
        
    }
    
    int top() {
        if(min_stack.top() > 0) //Decode the top to get val
            return min_stack.top() + current_min;
        else{
            //not need to decode, current min is holding the 
            //original value as top<0 means, it was a min and
            //current_min was updated for this value.
            return current_min;
        }
    }
    
    int getMin() {
        return current_min;
    }
    private:
    stack<long> min_stack;
    int current_min;
};
