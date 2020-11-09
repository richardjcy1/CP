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
        int x;
        cin >> x;
        int ans = 0;
        bool ok = false;
        for (int i = 1; i <= 9; i++)
        {
            string s = to_string(i);
            while (stoi(s) <= 9999 && stoi(s) != x)
            {
                ans += (int)(s.size());
                s += to_string(i);
            }
            if (stoi(s) == x)
            {
                ans += (int)(s.size());
                ok = true;
            }
            if (ok) break;
        }
        cout << ans << endl;
    }
    return 0;
}