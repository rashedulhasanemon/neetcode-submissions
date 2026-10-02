class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lcs = 0;

        //Method 1: T->O(n), space->O(n)
        //Setify the nums array. This will also remove the duplicates.
        // std::unordered_set<int> nums_set(nums.begin(), nums.end());

        //For each number from set, check if there is no immediate smaller value.
        //If no imm smaller value, it is a start of a sequence. Count how many consecutive
        //numbers are there in the set starting from the number. Update the lcs if the
        //current sequence is larger than previous.

        // for(auto val: nums_set){
        //     if(nums_set.contains(val - 1)) 
        //         continue;
        //     int current_lcs = 0;
        //     while(nums_set.contains(val)){
        //         current_lcs++;
        //         val++;
        //     }
        //     lcs = max(lcs, current_lcs);
        // }

        //-----------------x----------------

        //Method 2: time->O(nlogn), space->O(1)
        // if(nums.size() == 0) return 0;
        // std::sort(nums.begin(), nums.end());
        // int curr_lcs = 1;
        // for(int i = 0; i < (nums.size() - 1) ; i++){
        //     if(nums[i] == nums[i + 1]) continue;
        //     if((nums[i] + 1) == (nums[i + 1])){
        //         curr_lcs++;
        //     } 
        //     else{
        //         lcs = max(lcs, curr_lcs);
        //         curr_lcs = 1;
        //     }
        // }
        // lcs = max(lcs, curr_lcs);
        //---------------x-----------------

        //Method 3: Time->O(n), space->O(n)
        //Take a map of nums.size long, take val as keys, 
        //and use it to find existing chains.
        //Init the map with 0.
        //For each value in nums, calculate the left consecutive chain len and right 
        //consecutive chain len, then bind these like left_len+1+right_len.
        //update the new chains start val and end value.
        //Update the lcs
        //return the lcs
        std::unordered_map<int, int> chain_map;
        int i = 0;
        for(auto &val: nums){
            // cout<<"Step "<<i++<<" val: "<< val<<"\n";
            //Check for duplicates
            if(chain_map.contains(val)) continue;

            //find left, right chain len and calculate the new len
            int left_chain_len = 0;
            int right_chain_len = 0;
            if(chain_map.contains(val - 1))
                left_chain_len = chain_map[val - 1];
            if(chain_map.contains(val + 1))
                right_chain_len = chain_map[val + 1];

            int new_chain_len = left_chain_len + 1 + right_chain_len;
            // cout<<"left_chain_len: "<<left_chain_len<<" right_chain_len: "<<right_chain_len
            // <<" new_chain_len: "<<new_chain_len<<"\n";

            //update the new chain left head
            chain_map[val - left_chain_len] = new_chain_len;
            //update the new chain right head
            chain_map[val + right_chain_len] = new_chain_len;
            //If no left right chain, val is now only single len chain, also
            //assigning the new len in val will mark it as visited, so
            //will filter the duplicates in future
            chain_map[val] = new_chain_len;
            //update the lcs as per new chain
            lcs = max(lcs, new_chain_len);
        }

        return lcs;
    }
};
