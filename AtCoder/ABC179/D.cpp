#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }
    map<ll, ll> mp;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            for (int j = 0; j < k; j++)
            {
                mp[i + v[j].first]++;
                mp[i + v[j].first] %= mod;
                mp[i + v[j].second + 1]--;
                mp[i + v[j].second + 1] %= mod;
            }
        }
        else
        {
            sum += mp[i];
            if (sum > 0)
            {
                for (int j = 0; j < k; j++)
                {
                    mp[i + v[j].first] += sum;
                    mp[i + v[j].first] %= mod;
                    mp[i + v[j].second + 1] -= sum;
                    mp[i + v[j].second + 1] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += mp[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}