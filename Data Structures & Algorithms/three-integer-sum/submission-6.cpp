class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       std::sort(nums.begin(), nums.end());
    //    for(int val: nums) cout<<val<<" ";
    //    cout<<"\n";
       vector<vector<int>> res;
       int i = 0;
       while(i < nums.size()){
            
            int a = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){                    
                // cout<<"left: "<<left<<" right: "<<right<<"\n";

                int b = nums[left];
                int c = nums[right];
                // cout<<a<<"+"<<b<<"+"<<c<<"="<<(a+b+c)<<"\n";
                if((a + b + c) > 0) --right;
                if((a + b + c) < 0) ++left;
                if((a + b + c) == 0){
                    res.push_back({a,b,c});
                    ++left;
                    while( (left < right) && (nums[left] == nums[left - 1])){
                    left++;
                }

                }
                // cout<<"After: "<<"left: "<<left<<" right: "<<right<<"\n";
            }
            ++i;
            while((i < nums.size()) && (nums[i] == nums[i - 1])) ++i;
       }
    return res;

    }
    
};
