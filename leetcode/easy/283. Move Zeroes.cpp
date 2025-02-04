class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int left = 0, nums_size = nums.size() - 1;
    for (int right = 0; right <= nums_size; ++right)
    {
        if (nums[left] == 0 && nums[right] != 0)
        {
            nums[left] = nums[right];
            nums[right] = 0;
        }
        if (nums[left] != 0) left++;
    }
    }
};
