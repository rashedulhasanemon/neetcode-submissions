class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> pos_speed(size);
        for(int i = 0; i < size; ++i){
            pos_speed[i] = {position[i], speed[i]};
        }
        sort(pos_speed.begin(), pos_speed.end(), 
        [](pair<int,int> a, pair<int,int> b)
        {return a.first > b.first;});

        // for(auto& car: pos_speed) cout<<"Pos "<<car.first<<" Speed "<<car.second<<"\n";
        stack<pair<int, int>> fleets_stk;

        for(auto &behind: pos_speed){
            if(fleets_stk.size()){
                pair<int,int> ahead = fleets_stk.top();
                double time_behind = ((double(target) -
                double(behind.first))/double(behind.second));
                double time_ahead = ((double(target) -
                double(ahead.first))/double(ahead.second));

                // cout<<"time_behind "<< time_behind<< " time_ahead "<<time_ahead<<"\n";
                if( time_behind > time_ahead){
                    // cout<<"pushed "<<behind.first<<"\n";
                    fleets_stk.push(behind);
                }
            }
            else
                fleets_stk.push(behind);
            

    /*
                fleets_stk.push(car);

            if(fleets_stk.size() >= 2){
                pair<int,int> ahead, behind;
                behind = fleets_stk.top();
                fleets_stk.pop();
                ahead = fleets_stk.top();
                fleets_stk.pop();
                
                fleets_stk.push(ahead);
                if((target - behind.first)/behind.second > 
                    (target - ahead.first)/ahead.second){
                    fleets_stk.push(behind);
                }
            }
            */
        }
        return fleets_stk.size();
    }
};
