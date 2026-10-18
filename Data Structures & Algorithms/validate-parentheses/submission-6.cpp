class Solution {
public:
    bool isValid(string s) {
        std::stack<char> char_stack;
        std::unordered_map<char, char> open_close = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };


        for(auto& c: s){
            if(!open_close.contains(c))
                char_stack.push(c);
            else{
                if(char_stack.empty()) return false;
                if(char_stack.top() != open_close[c]) return false;
                char_stack.pop();
            }
        }
        return char_stack.empty();
    }
};
