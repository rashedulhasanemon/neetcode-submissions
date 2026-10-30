class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> pos_speed(size);
        for(int i = 0; i < size; ++i){
            pos_speed[i] = {position[i], speed[i]};
        }
        //Sort based on pos
        sort(pos_speed.begin(), pos_speed.end(), 
        [](pair<int,int> a, pair<int,int> b)
        {return a.first > b.first;});

        stack<pair<int, int>> fleets_stk;

        for(auto &behind: pos_speed){
            if(fleets_stk.size()){
                double time_behind = ((double(target) -
                behind.first)/behind.second);

                pair<int,int> ahead = fleets_stk.top();
                double time_ahead = ((double(target) -
                ahead.first)/ahead.second);

                //If the car behind is slow, it cannot join to the
                //car ahead, thus it forms a new fleet.
                if( time_behind > time_ahead){
                    fleets_stk.push(behind);
                }
            }
            else //Only for the first car
                fleets_stk.push(behind);
        }
        return fleets_stk.size();
    }
};
