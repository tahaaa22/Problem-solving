class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0, current_sum = 0;
        int nums_size = nums.size();
        if(nums.size() == 1) return nums[0];

        for(int i=0; i < nums_size;++i)
        {
            current_sum += nums[i];
            if(nums[(i + 1) % nums_size] <= nums[i])
            {
                max_sum = max(current_sum, max_sum);
                current_sum = 0;
            }
          
        }
        return max(current_sum, max_sum);

    }
};
