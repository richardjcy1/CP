#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

bool check(string s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1]) return false;
    }
    return true;
}

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
        string s;
        cin >> s;
        if (check(s)) cout << 0 << endl;
        else
        {
            string p1, p2;
            for (int i = 0; i < n / 2; i++)
            {
                p1 += "01";
                p2 += "10";
            }
            int i = 0, j = 0, cnt1 = 0, cnt2 = 0;
            while (j < n)
            {
                if (s[j] == p1[j]) 
                {
                    ++j;
                    continue;
                }
                while (j < n && s[j] != p1[j])
                {
                    ++j;
                }
                ++cnt1;
                ++j;
            }
            j = 0;
            while (j < n)
            {
                if (s[j] == p2[j]) 
                {
                    ++j;
                    continue;
                }
                while (j < n && s[j] != p2[j])
                {
                    ++j;
                }
                ++cnt2;
                ++j;
            }
            int ans = min(cnt1, cnt2);
            cout << ans << endl;
        }
    }
    return 0;
}