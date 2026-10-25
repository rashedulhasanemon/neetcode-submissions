class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<pair<int,int>> stk;
        vector<int> res(size,0);

        stk.push({0, temperatures[0]});
        for(int i = 0; i < size; ++i){
            // if(stk.size()){
                if(stk.top().second >= temperatures[i]){
                    stk.push({i,temperatures[i]});
                }
                else{
                      while(stk.size()){
                        if(stk.top().second >= temperatures[i]) break;
                        res[stk.top().first] = i - stk.top().first;
                        stk.pop();
                    }
                    stk.push({i,temperatures[i]});
                }
            // }
            // else
                // stk.push({i,temperatures[i]});
        }
        return res;
    }
};
