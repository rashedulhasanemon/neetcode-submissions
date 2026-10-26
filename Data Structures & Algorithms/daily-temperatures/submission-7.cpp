class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size,0);

        for(int i = size - 2; i >= 0; --i){
            //pssible warm day
            int warm_day = i + 1;
            while(warm_day < size){
                if(temperatures[warm_day] > temperatures[i]){
                    res[i] = warm_day - i;
                    break;
                }
                else{
                    if(!res[warm_day]) break;
                    warm_day = warm_day + res[warm_day]; //Jump to next warm day
                }
            }
        }
        return res;
    }
};
