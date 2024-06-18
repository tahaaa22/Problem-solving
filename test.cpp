#include <vector>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set <int>s;
        for (int num : nums )
        {
            s.insert(num);
        }
        if (s.size() == nums.size())
            return false;
        return true;

    }
};


