class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size() < k) return false;
        if(s.size() == k) return true;
        vector<int> freq(26);
        int odd = 0;
        // increment the values of index
        for(auto ch : s) freq[ch - 'a']++;

        for(int i =0; i < 26; ++i)
        {
            if(freq[i] % 2 != 0)
            odd++;

        }
        return (odd <= k);
    }
};
