#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct BIT
{
    vector<ll> bit;
    int n;
    BIT() {init(-1);}
    BIT(int n_) {init(n_);}
    void init(int n_)
    {
        n = n_;
        bit.clear();
        bit.resize(n + 1, 0);
    }
    
    ll sum(ll i)
    {
        ll s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, ll x)
    {
        if (i == 0) return;
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    
    ll sum0(ll i)
    {
        return sum(i + 1);
    }
    
    void add0(int i, ll x)
    {
        add(i + 1, x);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    BIT b(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        b.add0(a[i], 1);
        ans += (a[i] - b.sum(a[i]));
    }
    cout << ans << endl;
    for (int i = 1; i < n; i++)
    {
        ans += (n - a[i - 1] - 1 - a[i - 1]);
        cout << ans << endl;
    }
    return 0;
}