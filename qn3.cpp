#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        auto maxsum = nums[0];
        int current_sum = 0;
        for (n: nums)
        {
            current_sum = max(current_sum, 0);
            current_sum+= n;
            maxsum = max(current_sum, maxsum);
        }




    }
};