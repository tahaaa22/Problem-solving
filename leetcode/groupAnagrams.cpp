#include <iostream>
using namespace std;
#include<algorithm>
#include <vector>
#include <string>
#include<unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>>mp;
        for(const string& str: strs)
        {
            string current = str;
            sort(current.begin(), current.end());
            mp[current].push_back(str);
        }
        vector<vector<string>> result;
        result.reserve(mp.size());
    for(const auto& str: mp)
        {
            result.push_back(str.second);
        }
        return result;

    }
};