class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;

        while(l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            max_area = max(area, max_area);

            (heights[l] < heights[r]) ? ++l : --r; 
        }
        return max_area;
    }
};
