#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int w, n;
        cin >> w >> n;
        vector<int> a(w);
        for (int i = 0; i < w; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < w; i++)
        {
            ll tmp = 0;
            for (int j = 0; j < w; j++)
            {
                int x = min(a[i], a[j]);
                int y = max(a[i], a[j]);
                tmp += min(y - x, n - y + x);
            }
            ans = min(ans, tmp);
        }

        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}