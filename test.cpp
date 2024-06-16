#include <vector>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        set<int>myset;
        if(s.size() != t.size())
            return false;
        for(int i =0; i < s.size() ; i++)
        {
            myset.insert(s[i]);
            myset.insert(t[i]);
        }
        s.

    }
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    Solution s;
   cout<< s.hasDuplicate(a);
}
