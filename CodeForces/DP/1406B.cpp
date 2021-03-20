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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = max({a[4]*a[3]*a[2]*a[1]*a[0], a[3]*a[2]*a[1]*a[0]*a[n-1],
        a[2]*a[1]*a[0]*a[n-1]*a[n-2],a[1]*a[0]*a[n-1]*a[n-2]*a[n-3],a[0]*a[n-1]*a[n-2]*a[n-3]*a[n-4],
        a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]});
        cout << ans << endl;
    }
    return 0;
}