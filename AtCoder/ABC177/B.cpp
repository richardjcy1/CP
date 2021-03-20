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
    cin >> s >> t;
    int m = s.size(), n = t.size();
    int ans = n;
    for (int i = 0; i + n <= m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[i + j] != t[j]) ++cnt;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}