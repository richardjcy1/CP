#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i] >> p[i];
    }
    map<int, ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]] += p[i];
        mp[t[i]] -= p[i];
    }
    ll tot = 0;
    bool ok = true;
    for (auto p: mp)
    {
        tot += p.second;
        if (tot > w)
        {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}