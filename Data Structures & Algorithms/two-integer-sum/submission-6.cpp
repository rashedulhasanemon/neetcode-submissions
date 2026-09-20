class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_idx;
        
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(num_idx.find(comp) != num_idx.end()) return {num_idx[comp], i};
            num_idx.insert({nums[i], i});
        }
        return {};
    }
};

//123
//456