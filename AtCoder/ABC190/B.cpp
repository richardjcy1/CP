#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, s, d;
    cin >> n >> s >> d;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) cin >> x[i] >> y[i];
    bool ok = false;
    for (ll i = 0; i < n; i++)
    {
        if (x[i] >= s || y[i] <= d) continue;
        else 
        {
            ok = true;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}