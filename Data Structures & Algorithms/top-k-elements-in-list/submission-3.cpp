class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num_freq_map;
        for(auto &num: nums){
            num_freq_map[num]++;
        }

        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> min_heap;

        for(auto &pair: num_freq_map){
            min_heap.push({pair.second, pair.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        } 

        std::vector<int> topk;
        for(int i = 0; i < k; i++){
            topk.push_back(min_heap.top().second);
            min_heap.pop();
        }        
        return topk;
    }
};
