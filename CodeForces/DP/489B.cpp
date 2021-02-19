#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (a[i] + 1 < b[j])
        {
            ++i;
            continue;
        }
        if (b[j] + 1 < a[i])
        {
            ++j;
            continue;
        }
        ++ans;
        ++i;
        ++j;
    }
    cout << ans << endl;
    return 0;
}