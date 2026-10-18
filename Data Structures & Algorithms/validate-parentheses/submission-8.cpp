class Solution {
public:
    bool isValid(string s) {
        std::stack<char> char_stack;
        std::unordered_map<char, char> close_open = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(auto& c: s){
            if(!close_open.contains(c))
                char_stack.push(c);
            else{
                if(char_stack.empty()) return false;
                if(char_stack.top() != close_open[c]) return false;
                char_stack.pop();
            }
        }
        return char_stack.empty();
    }
};
