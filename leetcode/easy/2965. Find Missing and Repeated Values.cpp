class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int width = grid.size();
        int height = grid[0].size();
        vector<int> frequencies(width * height + 1, 0);
        vector<int> result;
        int repeated_num =0, missing_num=0;

        for(int i =0 ; i < grid.size(); ++i)
        {
            for(int j = 0 ; j < grid[0].size(); ++j)
            {
                frequencies[grid[i][j]]++;
            }
        }
        for(int i = 0 ; i < frequencies.size(); ++i)
        {
            if(frequencies[i] > 1) repeated_num = i;
            if(frequencies[i] == 0) missing_num = i;
        }
        result.push_back(repeated_num);
        result.push_back(missing_num);
        return result;
    }
};
