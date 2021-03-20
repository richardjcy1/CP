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
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        bool ok = true;
        int tmp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] < tmp)
            {
                ok = false;
                break;
            }
            if (v[i] < v[i + 1]) tmp += v[i + 1] - v[i];
        }
        if (v[n - 1] < tmp) ok = false;
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}