#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> a(4);
        for (int i = 0; i < 4; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = a[0] * a[2];
        cout << ans << endl;
    }
    return 0;
}