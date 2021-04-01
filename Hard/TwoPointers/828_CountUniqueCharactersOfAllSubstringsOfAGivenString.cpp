typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int uniqueLetterString(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<ll> a(26, -1);
        vector<ll> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'A';
            left[i] = a[idx];
            a[idx] = i;
        }
        a = vector<ll>(26, n);
        for (int i = n - 1; ~i; i--)
        {
            int idx = s[i] - 'A';
            right[i] = a[idx];
            a[idx] = i;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll l = i - left[i] - 1;
            ll r = right[i] - i - 1;
            ans = (ans + (l + 1) * (r + 1)) % mod;
        }
        return ans;
    }
};