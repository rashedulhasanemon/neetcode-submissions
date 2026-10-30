class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> pos_speed(size);
        for(int i = 0; i < size; ++i){
            pos_speed[i] = {position[i], speed[i]};
        }
        //Sort based on pos
        sort(pos_speed.rbegin(), pos_speed.rend());
        for(auto& pair: pos_speed) cout<<pair.first<<" ";
        vector<double> fleets_stk;

        for(auto &behind: pos_speed){
            fleets_stk.push_back((double(target) -
            behind.first)/behind.second);
            if((fleets_stk.size() >= 2) && (fleets_stk[fleets_stk.size()-1] <=
            fleets_stk[fleets_stk.size()-2])){
                fleets_stk.pop_back();
            }
        }
        return fleets_stk.size();
    }
};
