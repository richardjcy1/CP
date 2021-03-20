#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
    {
         //cout << "num " << a << endl;
         //cout << "Inverse doesn't exist" << endl;
         return INF;
    }
    else
    {
        ll res = (x % m + m) % m;
        //cout << "Modular multiplicative inverse of " << a << "is " << res << endl;
        return res;
    }
}

ll power(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    
    while (n)
    {
        if (n & 1) res = (res * a ) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    unordered_map<ll, ll> mp1;
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] != 0) ++cnt1;
        else if (b[i] == 0 && a[i] != 0) ++cnt2;
        else if (a[i] != 0 && b[i] != 0)
        {
            ll x;
            if (b[i] > 0) x = a[i] * modInverse(b[i], mod);
            else
            {
                x = a[i] * modInverse(-b[i], mod);
                x %= mod;
                x *= -1;
                x = (x + mod) % mod;
            }
            x = (x + mod) % mod;
            mp1[x]++;
        }
        else cnt3 = 1;
    }
    ll ans = 1;
    unordered_set<ll> st;
    for (auto p: mp1)
    {
        if (st.find(p.first) != st.end()) continue;
        ll u = 1;
        u = (u * p.first) % mod;
        u *= -1;
        u = (u + mod) % mod;
        ll v = modInverse(u, mod);
        v = (v + mod) % mod;
        if (mp1.find(v) != mp1.end())
        {
            //cout << p.second << " " << mp1[v] << endl;
            st.insert(p.first);
            st.insert(v);
            ll x = (power(2, p.second, mod) % mod + power(2, mp1[v], mod) - 1) % mod;
            ans *= x;
            ans %= mod;
        }
        else 
        {
            ll x = power(2, p.second, mod) % mod;
            st.insert(p.first);
            //cout << p.second << endl;
            ans *= x;
            ans %= mod;
        }
    }
    if (cnt1 && cnt2)
    {
        ll x = (power(2, cnt1, mod) % mod + power(2, cnt2, mod) - 1) % mod;
        x = (x + mod) % mod;
        ans *= x;
        ans %= mod;
    }
    else if (cnt1)
    {
        ll x = power(2, cnt1, mod) % mod;
        ans *= x;
        ans %= mod;
    }
    else if (cnt2)
    {
        ll x = power(2, cnt2, mod) % mod;
        ans *= x;
        ans %= mod;
    }
    if (cnt3) ++ans;
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}