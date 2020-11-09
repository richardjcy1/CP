#include <bits/stdc++.h>
using namespace std;



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
        bool is_cycle_clock = true;
        bool is_cycle_anti = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                is_cycle_clock = false;
            }
            if (s[i] == '>')
            {
                is_cycle_anti = false;
            }
        }
        if (is_cycle_clock || is_cycle_anti)
        {
            cout << n << endl;
        }
        else
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '-' || s[(i - 1 + n) %n] == '-') ++ans;
            }
            cout << ans << endl;
        }
    }
    return 0;
}