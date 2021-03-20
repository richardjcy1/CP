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
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int cnt = 0;
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R' && b)
            {
                 b--;
                 cnt++;
                 ans += 'P';
            }
            else if (s[i] == 'P' && c)
            {
                 c--;
                 cnt++;
                 ans += 'S';
            }
            else if (s[i] == 'S' && a)
            {
                 a--;
                 cnt++;
                 ans += 'R';
            }
            else ans += '.';
        }
        bool ok = false;
        if (cnt >= (n + 1) / 2) ok = true;
        if (!ok) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == '.')
                {
                    if (a)
                    {
                        ans[i] = 'R';
                        --a;
                    }
                    else if (b)
                    {
                        ans[i] = 'P';
                        --b;
                    }
                    else if (c)
                    {
                        ans[i] = 'S';
                        --c;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}