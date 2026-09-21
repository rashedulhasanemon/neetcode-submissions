class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num_freq_map;
        for(auto &num: nums){
            num_freq_map[num]++;
        }
        std::vector<std::pair<int, int>> num_freq_pair(num_freq_map.begin(), num_freq_map.end());
        std::sort(num_freq_pair.begin(), num_freq_pair.end(), [](auto &a, auto &b){return a.second > b.second;});

        std::vector<int> topk;
        for(int i = 0; i < k; i++){
            topk.push_back(num_freq_pair[i].first);
        }        
        return topk;
    }
};
