class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int left = 0;
        // int right = numbers.size() - 1;

        // while(left < right){
        //     if((numbers[left] + numbers[right]) == target){
        //         return {++left, ++right};
        //     }
        //     if((numbers[left] + numbers[right]) > target)
        //         right--;
        //     if((numbers[left] + numbers[right]) < target)
        //         left++;
        // }

        for(int i = 0; i < numbers.size(); i++){
            int num1 = numbers[i];
            int num2 = target - num1;
            int left = i + 1;
            int right = numbers.size() - 1;
            while(left <= right){
                int middle = (left + right) / 2;
                if( numbers[middle] > num2)
                    right = middle - 1;
                if( numbers[middle] < num2)
                    left = middle + 1;
                if( numbers[middle] == num2){
                    return {++i, ++middle};
                }
            }

        }
        return {};
    }
};
