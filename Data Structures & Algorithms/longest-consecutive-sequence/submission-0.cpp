class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int lcs = 0;

        for(auto val: nums_set){
            if(nums_set.contains(val - 1)) 
                continue;
            int current_lcs = 1;
            while(nums_set.contains(val + 1)){
                current_lcs++;
                val += 1;
            }
            lcs = max(lcs, current_lcs);
        }
        return lcs;
    }
};
