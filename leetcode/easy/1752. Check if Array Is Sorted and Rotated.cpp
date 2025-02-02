## approach one: 
# time complexity : O(nlogn) for sorting 
# space complexity : O(n) for the new  sorted vector
class Solution {
public:
    bool check(vector<int>& nums) {
        int position = 0;
        for(int i =1 ; i < nums.size(); ++i)
        {
            if(nums[i] < nums[i - 1])
            {
                 position= i;
                 break;
            }
        }
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(int i = 0 ; i < nums.size() - 1 ; ++i)
        {
            if(sorted[i] != nums[(i + position) % nums.size()])
            return false;
        }
        return true;
    }
};

## approach two: 
# time complexity : O(n) 
# space complexity : O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Check each adjacent pair (wrapping around at the end)
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
