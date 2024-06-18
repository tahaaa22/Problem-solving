#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int> m;
        for(int i =0 ; i< nums.size();i++)
        {
            int comp = target - nums[i];
            if(m.count(comp))
            {
                return {i, m[comp]};
            }
            m[nums[i]] = i;
        }
        return {};


    }
};