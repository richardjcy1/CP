#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*a:A1+A2
    b:B1+B2
    max(A1+B1-A2)
    A1+A2=A
    B1+B2=B
    A1+B1=A+B-A2-B2
    A1+B1-A2=A+B-2*A2-B2 > 0
    */
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll tota = accumulate(a.begin(), a.end(), (ll)0);
    ll totb = accumulate(b.begin(), b.end(), (ll)0);
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) v.push_back(make_pair(a[i], b[i]));
    sort(v.begin(), v.end(), [&](const pair<ll, ll>& x, const pair<ll, ll>& y)
    {
        return 2 * x.first + x.second < 2 * y.first + y.second;
    });
    int i = 0;
    ll tot = tota + totb;
    for (; i < n; i++)
    {
        tot = tot - (2 * v[i].first + v[i].second);
        if (tot <= 0) break;
    }
    cout << n - i << endl;
    return 0;
}