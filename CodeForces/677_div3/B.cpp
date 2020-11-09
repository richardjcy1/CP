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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<pair<int, int>> a;
        int start = 0, end = 0;
        while (end < n)
        {
            if (!v[end])
            {
                ++end;
                start = end;
                continue;
            }
            while (end < n && v[end])
            {
                ++end;
            }
            a.push_back(make_pair(start, end - 1));
            start = end;
        }
        if (start != end) a.push_back(make_pair(start, end - 1));
        int ans = 0;
        if ((int)a.size() == 1) cout << 0 << endl;
        else
        {
            int m = a.size();
            for (int i = 1; i < m; i++)
            {
                ans += a[i].first - a[i - 1].second - 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}