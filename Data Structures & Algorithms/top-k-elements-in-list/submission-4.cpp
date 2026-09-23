class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num_freq_map;
        for(auto &num: nums){
            num_freq_map[num]++;
        }

        std::vector<vector<int>> buckets(nums.size() + 1);
        for(auto &pair: num_freq_map){
            buckets[pair.second].push_back(pair.first);
        }
        std::vector<int> topkFreq;
        for(int i = buckets.size() - 1; i > 0; i--){
            for(auto &val: buckets[i]){
                topkFreq.push_back(val);
            }
            if(topkFreq.size() == k) return topkFreq;
        }
        return topkFreq;
    }
};


//Method 1: Count frequencies and map with their values -> sort by frequency -> return top k values as per their freq. T->O(nlogn), S->O(n).
//Method 2: Count frequencies and map with their values -> put the pair in a priority queue as min heap by their frequencies, store upto k top entry as per their freq -> return the min heap values. T->O(nlogk) as min heap will contain up to k entries. S->O(n+k).
//Method 3: Count frequencies and map with their values -> use the frequencies as a array/vector index, the freq could be at most the original passed array size i.e total entry size. -> return from the vector in backward upto k entries. T->O(n), S->O(n)