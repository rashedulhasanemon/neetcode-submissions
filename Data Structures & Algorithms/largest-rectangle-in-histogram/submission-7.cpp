class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        size_t size = heights.size();
        stack<int> stk;
        int max_area = 0;
        for (int i = 0; i < size; i++) {
            while (stk.size() && heights[i] <= heights[stk.top()]) {
                int bar_idx = stk.top();    
                stk.pop();
                int left_bound = stk.size()? stk.top() : -1;
                int width = i-1-left_bound;
                int area = width * heights[bar_idx];
                max_area = max(max_area, area);
            }
            stk.push(i);
        }
        return max_area;
    }
};