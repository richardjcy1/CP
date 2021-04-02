typedef long long ll;

// find the longest palindrome substring starting from index 0
// by checking hash value in original and reverse order
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        ll prefix = 0, suffix = 0;
        ll base = 31, mod = 1e9 + 7, mul = 1;
        int happy = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix = (prefix * base + (s[i - 1] - 'a')) % mod;
            suffix = (suffix + (s[i - 1] - 'a') * mul) % mod;
            if (prefix == suffix) happy = i;
            mul = (mul * base) % mod;
        }
        string rem = s.substr(happy);
        reverse(rem.begin(), rem.end());
        return rem + s;
    }
};