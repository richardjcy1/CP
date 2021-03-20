#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
ll dp[maxn][11][3];
ll m, n, k, x;
vector<vector<int>> g;
vector<bool> vis;
// dp[v][rem][flag]
// flag == 0 (< k): (k - 1) * (dp[nei][rem][0] + dp[nei][rem][1] + dp[nei][rem][2])
// flag == 1 (== k): dp[nei][rem - 1][0]
// flag == 2 (> k): (m - k) * dp[nei][rem][0]

ll fac[11];

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

void factorial()
{
    fac[0] = 1;
    for (ll i = 1; i < 11; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

ll modInverse(ll n, int p)
{
    return power(n, p - 2, p);
}

ll nCrModPFermat(ll n, int r, int p)
{
    if (r == 0) return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

ll combine(ll a, ll b)
{
    ll ans = 1;
    if (b > a / 2) b = a - b;
    for (ll i = 0; i < b; i++)
    {
        ans = (ans * a) % mod;
        --a;
    }
    ans /= fac[b];
    ans %= mod;
    return ans;
}

// void comb()
// {
//     c[1][0] = c[1][1] = 1;
//     for (int i = 2; i <= x; i++)
//     {
//         c[i][0] = c[i][i] = 1;
//         for (int j = 1; j < i; j++)
//         {
//             c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//         }
//     }
// }

ll solve(int v, int rem, int flag)
{
    if (dp[v][rem][flag] >= 0) return dp[v][rem][flag];
    if (k == 1 && flag == 0) return 0;
    if (k == m && flag == 2) return 0;
    // dp[v][rem][flag] = -2;
    vis[v] = true;
    ll ans = 1;
    bool ok = false;
    if (flag == 0)
    {
        ll cnt = 0;
        for (int nei: g[v])
        {
            ll tmp = 0;
            if (!vis[nei])
            {
                ok = true;
                ++cnt;
                tmp = (tmp + solve(nei, rem, 0)) % mod;
                tmp = (tmp + solve(nei, rem, 1)) % mod;
                tmp = (tmp + solve(nei, rem, 2)) % mod;
                ans = (ans * tmp) % mod;
            }
        }
        if (ok) 
        {
            for (ll i = rem + 1; i <= cnt; i++)
            {
                ll tmp = ((nCrModPFermat(cnt, i, mod) % mod) * (ll)power(m - 1, cnt - i, mod)) % mod;
                ans = (ans - tmp + mod) % mod;
            }
            ans = (ans * (k - 1)) % mod;
        }
    }
    else if (flag == 1)
    {
        for (int nei: g[v])
        {
            if (rem >= 1 && !vis[nei])
            {
                ok = true;
                ans = (ans * solve(nei, rem - 1, 0)) % mod;
            }
            else if (rem < 1) ans = 0;
        }
    }
    else
    {
        for (int nei: g[v])
        {
            ll tmp = 0;
            if (!vis[nei])
            {
                ok = true;
                tmp = (tmp + solve(nei, rem, 0)) % mod;
                tmp = (tmp + solve(nei, rem, 2)) % mod;
                ans = (ans * tmp) % mod;
            }
        }
        if (ok) ans = (ans * (m - k)) % mod;
    }
    // if (!ok) ans = 0;
    // cout << v << " " << rem << " " << flag << " " << ans << endl;
    return dp[v][rem][flag] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    factorial();
    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>());
    vis = vector<bool>(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k >> x;
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    // comb();
    for (int i = 0; i < 3; i++)
    {
        ans = (ans + solve(0, x, i)) % mod;
        vis = vector<bool>(n);
    }
    cout << ans << endl;
    return 0;
}