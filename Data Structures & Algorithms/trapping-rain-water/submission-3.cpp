class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> lm(size, 0);
        vector<int> rm(size, 0);
        int total_water = 0;
        
        lm[0] = 0;
        rm[size - 1] = 0;
        int prev_lm = 0;
        for(int i = 1; i < size; ++i){
            if(prev_lm > height[i - 1]){
                lm[i] = prev_lm;
            }
            else
                lm[i] = height[i - 1];

            //update prev_lm
            prev_lm = lm[i];
        }
        int prev_rm = 0;
        for(int i = size - 2; i >=0; --i){
            if(prev_rm > height[i + 1])
                rm[i] = prev_rm;
            else
                rm[i] = height[i + 1];

            //update prev_rm
            prev_rm = rm[i];
        }

        for(int i = 0; i < size; ++i){
            int water_i = min(lm[i], rm[i]) - height[i];
            total_water += max(0, water_i);
        }
        return total_water;

    }
};
