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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) mp[a[i]]++;
        int ma = INF;
        for (auto p: mp)
        {
            if (p.second == 1)
            {
                if (p.first < ma)
                {
                    ma = p.first;
                }
            }
        }
        if (ma == INF) cout << -1 << endl;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == ma)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}