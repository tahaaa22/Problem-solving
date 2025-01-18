class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count = 0;
        for (auto& num : derived)
        {
            if (num == 1) count++;
        }
        if (count % 2 == 0)
            return true;
        return false;
        
    }
};
