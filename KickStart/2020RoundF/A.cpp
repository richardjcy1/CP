#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            b[i] = ceil(a[i] / (m + 0.0));
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[b[i]].push_back(i + 1);
        }
        cout << "Case #" << k++ << ": ";
        for (auto p: mp)
        {
            for (int i: p.second) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}