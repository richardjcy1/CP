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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] * 2 < a[i + 1])
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
        else ++cnt;
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}