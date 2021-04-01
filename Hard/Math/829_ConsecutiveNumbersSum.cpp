typedef long long ll;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (ll i = 1; ; i++)
        {
            ll tmp = 2 * (ll)n - i * i + i;
            if (tmp <= 0) break;
            if (tmp % (2 * (ll)i) == 0) ++ans;
        }
        return ans;
    }
};