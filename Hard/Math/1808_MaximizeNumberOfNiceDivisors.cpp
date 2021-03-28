typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll power(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    
    while (n)
    {
        if (n & 1) res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

class Solution {
public:
    int maxNiceDivisors(int p) {
        if (p == 1) return 1;
        ll x = p;
        if (x % 3 == 0)
        {
            return power(3, x / 3, mod);
        }
        else if (x % 3 == 1)
        {
            return power(3, x / 3 - 1, mod) * 4 % mod;
        }
        else
        {
            return power(3, x / 3, mod) * 2 % mod;
        }
        return -1;
    }
};