class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> stk;
        vector<int> res(size,0);

        for(int i = 0; i < size; ++i){
            while(stk.size() && (temperatures[i] > temperatures[stk.top()])){
            int top_idx = stk.top();
            if(temperatures[top_idx] >= temperatures[i]) break;
            res[top_idx] = i - top_idx;
            stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
