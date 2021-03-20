#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll a = 0;
    double b = 0.0;
    ll c = 0;
    for (int i = 0; i < n; i++) 
    {
        a += abs(v[i]);
        c = max(c, abs(v[i]));
        b += v[i] * v[i];
    }
    double ans = sqrt(b);
    cout << setprecision(18) << a << endl << ans << endl << c << endl;
    return 0;
}