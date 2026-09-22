class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num_freq_map;
        for(auto &num: nums){
            num_freq_map[num]++;
        }
        std::vector<std::pair<int, int>> num_freq_pair;
        for(auto &pair: num_freq_map){
            num_freq_pair.push_back({pair.second, pair.first});
        }
        std::sort(num_freq_pair.rbegin(), num_freq_pair.rend());

        std::vector<int> topk;
        for(int i = 0; i < k; i++){
            topk.push_back(num_freq_pair[i].second);
        }        
        return topk;
    }
};
