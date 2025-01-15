vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = pow(2, maximumBit) - 1;
        int n = nums.size();
        vector<int>ans(n);
            for(int i = 0 ; i < nums.size(); ++i )
            {
                k ^= nums[i];
                ans[n - 1 -i] = k;
            }
        return ans;

    }
