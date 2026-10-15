class Solution {
public:
    int trap(vector<int>& height) {
        int lm = 0;
        int rm = 0;
        int total_water = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l <= r){
            if(lm < rm){
                total_water += max(0, lm - height[l]);
                
                lm = max(lm, height[l++]);
            }
            else{
                total_water += max(0, rm - height[r]);
                rm = max(rm, height[r--]);
            }
        }
        return total_water;
    }
};
