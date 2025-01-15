#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int>m1;
        for(char x : s)
        {
            m1[x]++;
        }
        for(char x : t)
        {
            m1[x]--;
        }
        for(auto x: m1)
        {
            if(x.second != 0)
                return false;
        }
        return true;


    }
};
int main()
{
    string s=   "jam";
    string t = "jar";
    Solution so;
    bool f = so.isAnagram(s,t);
cout << f;

    return 0;
}
