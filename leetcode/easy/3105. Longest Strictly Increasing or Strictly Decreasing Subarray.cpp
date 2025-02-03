class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int longest_increase = 1;
        int longest_decrease = 1;
        int current_sum = 0;
  
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] < nums[i])
            {
                longest_increase++;
            }
            else
            {
                current_sum = max(current_sum, longest_increase);
                longest_increase = 1;
            }
        }
        longest_increase = max(current_sum, longest_increase);
        current_sum = 0;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i - 1] > nums[i])
            {
                longest_decrease++;
            }
            else
            {
                current_sum = max(current_sum, longest_decrease);
                longest_decrease = 1;
            }
        }
        longest_decrease = max(current_sum, longest_decrease);

        return max(longest_decrease, longest_increase);

    }
};
