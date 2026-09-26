class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> result(size, 1);
        int postfix = 1;

        //Calculate prefix product for each value
        for(int i = 1; i < size; i++){
            result[i] = (result[i - 1] * nums[i - 1]);
        }
        //Calculate the product with postfix product in place;
        for(int i = size - 1; i >= 0; i--){
            result[i] = result[i] * postfix;
            postfix *= nums[i];
        }
        return result;
    }
};
