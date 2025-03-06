class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> output;

        for(int i =0; i < nums_size - 1; ++i)
        {
            if(nums[i] == nums[i + 1] && nums[i] != 0)
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for(int &num : nums)
        {
            if(num != 0) output.push_back(num);
        }

        for(; output.size() < nums_size ;) output.push_back(0);

        return output;
    }
};
