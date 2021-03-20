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
        ll ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < w; i++) ans += (abs(a[i] - a[w / 2]));
        vector<int> mod(w);
        for (int i = 0; i < w; i++)
        {
            mod[i] = a[i] < (n - a[i]) ? a[i] : -(n - a[i]);
        }
        sort(mod.begin(), mod.end());
        int p = mod[w / 2];
        ll tot = 0;
        for (int i = 0; i < w; i++)
        {
            tot += abs(p - mod[i]);
        }
        ans = min(ans, tot);
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}
