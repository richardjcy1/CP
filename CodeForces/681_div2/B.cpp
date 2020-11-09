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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int n = s.size();
        int start = -1;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && start == -1) start = i;
            else if (s[i] == '0' && start != -1)
            {
                v.push_back(make_pair(start, i - 1));
                start = -1;
            }
        }
        if (start != -1) v.push_back(make_pair(start, n - 1));
        int m = v.size();
        vector<int> q;
        for (int i = 0; i < m - 1; i++)
        {
            q.push_back(v[i + 1].first - v[i].second - 1);
        }
        sort(q.begin(), q.end());
        int ans = m * a;
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            if (q[i] * b - a < 0)
            {
                ans += q[i] * b - a;
            }
            else break;
        }
        cout << ans << endl;
    } 
    return 0;
}