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
        string s;
        cin >> s;
        int n = s.size();
        int start = 0, end = 0, ans = INF, cnt = 0;
        vector<int> vis(4);
        while (end < n)
        {
            vis[s[end] - '0']++;
            if (vis[s[end] - '0'] == 1) ++cnt;
            while (cnt == 3)
            {
                ans = min(ans, end - start + 1);
                vis[s[start] - '0']--;
                if (vis[s[start] - '0'] == 0) --cnt;
                ++start;
            }
            ++end;
        }
        if (ans == INF) ans = 0;
        cout << ans << endl;
    }
    return 0;
}