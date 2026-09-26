class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         std::vector<int> result;
        int size = nums.size();
        int postfix = 1;

        //Calculate prefix product for each value
        result.push_back(1);
        for(int i = 1; i < size; i++){
            result.push_back(result[i - 1] * nums[i - 1]);
        }
        //Calculate the product with postfix product in place;
        for(int i = size - 1; i >= 0; i--){
            result[i] = result[i] * postfix;
            postfix *= nums[i];
        }
        return result;
    }
};
