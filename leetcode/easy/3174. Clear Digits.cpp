class Solution {
public:

    bool is_char(char c)
    {
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
    }
    bool is_integer(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }
string clearDigits(string s) {
    int string_size = s.size();
    string out;
    for (int i = 0; i < string_size; ++i)
    {
        if (is_integer(s[i]) && !out.empty())
        {
            out.pop_back();
        }
        else
        {
            out.push_back(s[i]);
        }
    }
    return out;
}
};
