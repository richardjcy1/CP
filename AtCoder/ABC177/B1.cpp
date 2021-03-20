#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> t >> s;
    int m = s.size(), n = t.size();
    int ans = m;
    for (int i = 0; i + m <= n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
        {
            tmp += (s[j] != t[i + j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}