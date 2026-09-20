class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] != t[i]) return false;
        // }
        // return true;
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for(int i =0; i < s.size(); i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        for(int i =0; i < s.size(); i++){
            if(s_map[s[i]] != t_map[s[i]]) return false;
        }
        return true;
    }
};
