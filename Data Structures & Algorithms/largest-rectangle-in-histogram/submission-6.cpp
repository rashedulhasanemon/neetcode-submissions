class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        size_t size = heights.size();
        stack<pair<int,int>> stk;
        int max_area = 0;
        for (int i = 0; i < size; i++) {
            pair<int, int> stk_top = {i, heights[i]};
            while (stk.size() && stk.top().second >= heights[i]) {
                stk_top = stk.top();
                stk.pop();
                int width = i - stk_top.first;
                int area = width * stk_top.second;
                max_area = max(max_area, area);
            }
            stk.push({stk_top.first, heights[i]});
        }
        heights.pop_back();
        return max_area;
    }
};