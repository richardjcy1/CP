#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vector<pair<ll, ll>> primeFactors(ll n)
{
    vector<pair<ll, ll>> res;
    if (n % 2 == 0)
    {
        ll cnt = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            ++cnt;
        }
        res.push_back(make_pair(2, cnt));
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) res.push_back(make_pair(i, 0));
        while (n % i == 0)
        {
            n /= i;
            res.back().second++;
        }
    }
    if (n > 2)
    {
         res.push_back(make_pair(n, 1));
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;
    auto v = primeFactors(n);
    for (auto p: v)
    {
        ll i;
        //cout << p.first << " " << p.second << endl;
        for (i = 1; i * (i + 1) <= 2 * p.second; i++);
        ans += i - 1;
    }
    cout << ans << endl;
    return 0;
}