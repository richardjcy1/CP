#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n) v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (ll i: v) cout << i << endl;
    return 0;
}