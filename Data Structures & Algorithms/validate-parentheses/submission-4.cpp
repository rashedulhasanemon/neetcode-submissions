class Solution {
public:
    bool isValid(string s) {
        std::stack<char> chars;

        for(auto& c: s){
            if(c == '(' || c == '{' || c == '[')
                chars.push(c);
            else{
                if(chars.empty()) return false;
                if((chars.top() == '(') && (c != ')')) return false;
                else if((chars.top() == '{') && (c != '}')) return false;
                else if((chars.top() == '[') && (c != ']')) return false;
                chars.pop();
            }
        }
        return chars.empty();
    }
};
