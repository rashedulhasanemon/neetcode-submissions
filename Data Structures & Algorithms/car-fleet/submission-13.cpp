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

        int count=0;
        //Previous fleets time taken to reach target
        double fleet_ahead_time = 0;
        for(auto &car: pos_speed){
            double curr_car_time = (double(target)-car.first)/car.second;
            if(curr_car_time > fleet_ahead_time){
                count++;
                fleet_ahead_time = curr_car_time;
            }
        }
        return count;
    }
};
