class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        size_t size = heights.size();
        stack<pair<int,int>> stk;
        int max_area = 0;
        for (int i = 0; i < size; i++) {
            if (stk.size() && heights[i] <= heights[stk.top().second]) {
                pair<int, int> curr_pair;
                while (stk.size() && heights[stk.top().second] >= heights[i]) {
                    curr_pair = stk.top();
                    stk.pop();
                    int width = i - curr_pair.first;
                    int area = width * heights[curr_pair.second];
                    max_area = max(max_area, area);
                }
                stk.push({curr_pair.first, i});
            } else {
                stk.push({i, i});
            }
        }
        while(stk.size()){
            pair<int,int> curr_pair = stk.top();
            stk.pop();
            int width = size - curr_pair.first;
            int area = heights[curr_pair.second]*width;
            max_area=max(max_area,area);
        }
        return max_area;
    }
};