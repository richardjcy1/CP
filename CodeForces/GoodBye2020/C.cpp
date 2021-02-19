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
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (i == 1 && s[i] == s[i - 1])
            {
                s[i] = '.';
                ++ans;
            }
            else if (s[i] == s[i - 1] || s[i] == s[i - 2])
            {
                s[i] = '.';
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}