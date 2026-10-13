class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> lm(size, 0);
        int total_water = 0;
        
        lm[0] = 0;
        for(int i = 1; i < size; ++i){
            lm[i] = max(lm[i-1], height[i-1]);
        }
        int prev_rm = 0;
        for(int i = size - 2; i >=0; --i){
          prev_rm = max(height[i + 1], prev_rm);
          int water_i = max(0, min(prev_rm, lm[i]) - height[i]);
          total_water += water_i;
        }

        return total_water;
    }
};
