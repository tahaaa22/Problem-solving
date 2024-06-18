#include <iostream>
#include <vector>
using namespace std;

/*
 * 53. Maximum Subarray
 * Given an integer array nums, find the subarray
 * with the largest sum, and return its sum.
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        auto maxsum = nums[0];
        int current = 0;
        for(int num : nums)
        {
            current = max(current, 0);
            current += num;
            maxsum = max(maxsum, current);
        }
        return maxsum;
    }
};
