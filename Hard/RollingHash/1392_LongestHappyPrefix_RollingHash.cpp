typedef long long ll;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        ll prefix = 0, suffix = 0;
        ll base = 31, mod = 1e9 + 7, mul = 1;
        int happy = 0;
        for (int i = 1; i < n; i++)
        {
            prefix = (prefix * base + (s[i - 1] - 'a')) % mod;
            suffix = (suffix + (s[n - i] - 'a') * mul) % mod;
            if (prefix == suffix) happy = i;
            mul = (mul * base) % mod;
        }
        return s.substr(0, happy);
    }
};