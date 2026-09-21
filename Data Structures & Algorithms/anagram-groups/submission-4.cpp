class Solution {
public:

    class ArrayHash{
        public:
        size_t operator()(const std::array<int, 26> &charFreq) const {
            size_t hash = 0;
            for(auto &val: charFreq){
                hash = hash * 31 + val;
            }
            return hash;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<int, 26>, std::vector<string>, ArrayHash> charFreq_to_str_map;
        std::vector<vector<string>> groups;

        for(auto &str: strs){
            std::array<int, 26> charFreq = {};
            for(char &c: str){
                charFreq[c - 'a']++;
            }
            charFreq_to_str_map[charFreq].push_back(str);
        }

        for(auto &entry: charFreq_to_str_map){
            groups.push_back(entry.second);
        }
        return groups;
    }
};
