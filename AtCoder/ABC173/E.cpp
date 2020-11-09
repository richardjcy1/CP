#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int u = pos.size(), v = neg.size();
    ll ans = 1;
    if (u == 0)
    {
        if (k & 1)
        {
            for (int i = v - 1; i >= v - k; i--)
            {
                ans *= neg[i];
                ans = (ans + mod) % mod;
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                ans *= neg[i];
                ans = (ans + mod) % mod;
            }
        }
    }
    else
    {
        int i = u - 1, j = 0;
        if (k & 1)
        {
            --k;
            ans *= pos[u - 1];
            --i;
            ans %= mod;
        }
        while (k)
        {
            if (i - 1 >= 0 && j + 1 < v)
            {
                if (pos[i] * pos[i - 1] > neg[j] * neg[j + 1])
                {
                    ans *= pos[i];
                    ans %= mod;
                    ans *= pos[i - 1];
                    ans %= mod;
                    i -= 2;
                }
                else
                {
                    ll x = neg[j] * neg[j + 1];
                    x %= mod;
                    ans *= x;
                    ans %= mod;
                    j += 2;
                }
            }
            else if (i - 1 >= 0)
            {
                ans *= pos[i];
                ans %= mod;
                ans *= pos[i - 1];
                ans %= mod;
                i -= 2;
            }
            else if (j + 1 < v)
            {
                ll x = neg[j] * neg[j + 1];
                x %= mod;
                ans *= x;
                ans %= mod;
                j += 2;
            }
            k -= 2;
        }
    }
    cout << (ans + mod) % mod << endl;

    return 0;
}