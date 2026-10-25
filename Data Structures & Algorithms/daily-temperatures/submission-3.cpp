class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> stk;
        vector<int> res(size,0);

        stk.push(0);
        for(int i = 1; i < size; ++i){
            if(temperatures[stk.top()] >= temperatures[i]){
                stk.push(i);
            }
            else{
                  while(stk.size()){
                    int top_idx = stk.top();
                    if(temperatures[top_idx] >= temperatures[i]) break;
                    res[top_idx] = i - top_idx;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};
