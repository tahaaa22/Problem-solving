#include <iostream>
using namespace std;
#include <vector>


//918. Maximum Sum Circular Subarray
//
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n]
//and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
//there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        // first of all I need the max and min to get the cir
        auto curmax = nums[0];
        auto curmin = nums[0];
        auto globmax = 0;
        auto globmin = 0;
        int total = 0;
        for (int n : nums)
        {
            curmax = max(curmax + n, n);
            curmin = min(curmin +n, n);
            total +=n;
            globmax = max(curmax, globmax);
            globmin = min(curmin, globmin);
        }
        if (globmax >0)
            return max(globmax, globmin);
        return globmax;

    }
};


