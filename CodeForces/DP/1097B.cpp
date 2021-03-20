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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    bool ok = false;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i)) tmp += a[i];
        }
        if (tmp % 360 == (sum - tmp) % 360 || (tmp % 360 == 0 && (sum - tmp) % 360 == 0))
        {
            ok = true;
            break;
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}