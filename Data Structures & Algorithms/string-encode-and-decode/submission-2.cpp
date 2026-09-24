class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_str;
        for(auto &str: strs){
            encoded_str += to_string(str.length()) + ":" + str;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        int idx = 0;
        std::vector<string> strs;
        if(!s.length()) return strs;
        do{
            std::string str;
            string len;
            while(s[idx] != ':'){
                len += s[idx++];
            }
            strs.push_back(s.substr(++idx, stoi(len)));
            idx += stoi(len);
        }
        while(idx < s.length());
        return strs;
    }
};
