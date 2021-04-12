typedef long long ll;

class Solution {
public:
    ll m, n, k;
    
    bool check(ll x)
    {
        ll ans = 0;
        for (ll i = 1; i <= m; i++)
        {
            ans += (min(x / i, n));
        }
        return ans >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        ll left = 1, right = 9e8 + 5;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (!check(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};