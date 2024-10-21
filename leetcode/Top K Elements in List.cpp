#include <vector>
#include <iostream>
using namespace std;
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        vector<int> result;
        result.reserve(k);
        // Count frequencies
        for (int num : nums) {
            frequencyMap[num]++;
        }
        // Find the top K frequent elements
        for (int i = 0; i < k; i++) {
            int currentMaxFreq = 0;
            int maxElement = 0;
            for (auto& pair : frequencyMap) {
                if (pair.second > currentMaxFreq) {
                    currentMaxFreq = pair.second;
                    maxElement = pair.first;
                }
            }
            result.push_back(maxElement);
            frequencyMap.erase(maxElement);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v = {5,5,2,3,1,4,4};
  cout << s.numRescueBoats(v, 5) << endl;

}
