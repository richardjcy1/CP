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
    vector<int> v(n), c(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(0, v[i] - c[i]);
    }
    cout << ans << endl;
    return 0;
}