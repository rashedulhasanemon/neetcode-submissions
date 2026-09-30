class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int lcs = 0;

        // for(auto val: nums_set){
        //     if(nums_set.contains(val - 1)) 
        //         continue;
        //     int current_lcs = 1;
        //     while(nums_set.contains(val + 1)){
        //         current_lcs++;
        //         val += 1;
        //     }
        //     lcs = max(lcs, current_lcs);
        // }
        if(nums.size() == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int curr_lcs = 1;
        for(int i = 0; i < (nums.size() - 1) ; i++){
            if(nums[i] == nums[i + 1]) continue;
            if((nums[i] + 1) == (nums[i + 1])){
                curr_lcs++;
            } 
            else{
                lcs = max(lcs, curr_lcs);
                curr_lcs = 1;
            }
        }
        lcs = max(lcs, curr_lcs);
        return lcs;
    }
};
