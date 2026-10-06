class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if((i > 0) && (nums[i] == nums[i - 1])) continue;
            if(nums[0] > 0) break;
            int a = nums[i];
            int left = i + 1;
            int right = size - 1;
            while(left < right){
                int b = nums[left];
                int c = nums[right];
                int sum = a + b + c;

                if(sum > 0) --right;
                else if(sum < 0) ++left;
                else if(sum == 0){
                    res.push_back({a,b,c});
                    ++left;
                    --right;
                    while((left < right) && (nums[left] == nums[left - 1]))
                        ++left;
                    while((left < right) && (nums[right] == nums[right + 1]))
                        --right;
                }
            }
        }
        return res;
    }
    
};
