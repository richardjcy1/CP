typedef long long ll;
const int P_B= 227;
const int P_M = 1000005;

class Solution {
public:
    string s;
    
    int solve(int left, int right)
    {
        if (left >= right) return 0;
        ll prefix = 0, suffix = 0, power = 1;
        for (int i = 0; i < (right - left) / 2; i++)
        {
            prefix = (prefix * P_B + s[left + i]) % P_M;
            suffix = (suffix + s[right - 1 - i] * power) % P_M;
            power = (power * P_B) % P_M;
            if (prefix == suffix)
            {
                if (s.substr(left, i + 1) == s.substr(right - 1 - i, i + 1))
                {
                    return 2 + solve(left + i + 1, right - 1 - i);
                }
            }
        }
        return 1;
    }
    
    int longestDecomposition(string text) {
        s = text;
        return solve(0, s.size());
    }
};