class Solution {
public:
    int l_max(vector<int>& height, int idx){
        int lmax = 0;
        for(int i = idx - 1; i >= 0; --i){
            lmax = max(height[i], lmax);
        }
        return lmax;
    }
    int r_max(vector<int>& height, int idx){
        int rmax = 0;
        for(int i = idx + 1; i < height.size(); i++){
            rmax = max(height[i], rmax);
        }
        return rmax;
    }
    int trap(vector<int>& height) {
        unordered_map<int, pair<int, int>> idx_lm_rm;
        int size = height.size();
        int total_water = 0;
        for(int i = 0; i < size; i++){
            int lmax = 0;
            int rmax = 0;
            if(idx_lm_rm.contains(i - 1)){
                if(idx_lm_rm[i - 1].first > height[i - 1]){
                    lmax = idx_lm_rm[i - 1].first;
                }
                else{
                    lmax = height[i - 1];
                }

                if(idx_lm_rm[i - 1].second > height[i]){
                    rmax = idx_lm_rm[i - 1].second;
                }
                else{
                    //now we dont know the rmax of the current ith bar. < condition
                    //cannot happen, for ==, we need to find the rmax so future bar
                    //can use it.
                    rmax = r_max(height, i);

                }
            }
            else{
                int lmax = l_max(height, i);
                int rmax = r_max(height, i);
            }
            idx_lm_rm[i] = {lmax, rmax};
            int water_i = (min(lmax, rmax) - height[i]);
            total_water += max(0,water_i);


            // int l_max = l_max(height, i);
            // int r_max = r_max(height, i);

            // int water_i = (min(l_max(height, i), r_max(height, i)) - height[i]);
            // total_water += max(0,water_i);
        }
        return total_water;
    }
};
