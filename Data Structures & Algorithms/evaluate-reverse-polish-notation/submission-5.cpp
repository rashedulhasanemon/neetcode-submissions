class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a = 0;
        int b = 0;
        stack<int> operands;
        // unordered_set<string> ops= {"+", "-", "*", "/"};

        for(auto &token : tokens){
            if(/*ops.contains(token)*/token == "+" || token == "-" || token == "*"||token=="/"){
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                
                if(token == "+"){
                    operands.push(a+b);
                    // cout<<a<<"+"<<b<<"="<<(a + b)<<"\n";
                    // cout<<"Push "<<(a+b)<<"\n";
                }
                else if(token == "-"){
                    operands.push(a-b);
                    // cout<<a<<"-"<<b<<"="<<(a - b)<<"\n";
                    // cout<<"Push "<<(a - b)<<"\n";
                }
                else if(token == "*"){
                    operands.push(a*b);
                    // cout<<a<<"*"<<b<<"="<<(a * b)<<"\n";
                    // cout<<"Push "<<(a*b)<<"\n";
                }
                else if(token == "/"){
                    operands.push(a/b);
                    // cout<<a<<"/"<<b<<"="<<(a / b)<<"\n";
                    // cout<<"Push "<<(a/b)<<"\n";
                }
            }
            else{
                // cout<<"Push "<<stoi(token)<<"\n";
                operands.push(stoi(token));
            }
        }
        return operands.top();        
    }
};
