class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        //Method 1: Sort and use two pointer.
        //time -> O(n^2), space -> if output is considered, O(n^2).

        // //sort the array to apply two pointer rules.
        // std::sort(nums.begin(), nums.end());
        // int size = nums.size();
        // for(int i = 0; i < size; i++){
        //     //skip the duplicates
        //     if((i > 0) && (nums[i] == nums[i - 1])) continue;
        //     //as the array is sorted, first num is zero means
        //     //there are no negative num so, no sum will result zero.
        //     if(nums[0] > 0) break;
        //     int a = nums[i];
        //     int left = i + 1;
        //     int right = size - 1;
        //     while(left < right){
        //         int b = nums[left];
        //         int c = nums[right];
        //         int sum = a + b + c;

        //         if(sum > 0) --right;
        //         else if(sum < 0) ++left;
        //         else if(sum == 0){
        //             res.push_back({a,b,c});
        //             ++left;
        //             --right;
        //             //skip left size duplicates.
        //             while((left < right) && (nums[left] == nums[left - 1]))
        //                 ++left;
        //             // while((left < right) && (nums[right] == nums[right + 1]))
        //             //     --right; //No need to handle right dupli, as it will auto dec
        //             //in the next itr if duplicates are present at the right side.
        //         }
        //     }
        // }




        //Method 2: Use map. Time O(N^2*logN^2) = O(N^2*logN), space -> O(K).

        std::set<vector<int>> res_set;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int a = nums[i];
            std::unordered_map<int, int> num_idx_mp;
            for(int j = i + 1; j < size; j++){
                int b = nums[j];
                int c = -(b+a);
                if(num_idx_mp.contains(c) && (num_idx_mp[c])){
                    vector<int> triplet = {a, b, c};
                    sort(triplet.begin(), triplet.end()); //time = 3log3
                    res_set.insert(triplet); //time = log(number of triplets, k)
                    //total time k*logk, k can be upto N^2!
                }
                else{
                    num_idx_mp[b] = j;
                }
            }
        }
        res.assign(res_set.begin(), res_set.end());


        return res;
    }
    
};
