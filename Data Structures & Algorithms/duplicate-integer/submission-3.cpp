class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> unique_nums = std::set<int>();

        while(nums.size()){
            if(unique_nums.insert(nums.at(nums.size()-1)).second == false) return true;
            nums.pop_back();
        }
        return false;
    }
};