class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int string_size = t.size();
        for(int right = 0 ; right < string_size;++right)
        {
            if(s[left] == t[right]) left++;
        }
        return (left == s.size());
    }
};
