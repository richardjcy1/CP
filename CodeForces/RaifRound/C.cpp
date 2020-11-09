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
        string s;
        cin >> s;
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty())
            {
                ans += s[i];
                continue;
            }
            else if ((ans.back() == 'A' && s[i] == 'B') || (ans.back() == 'B' && s[i] == 'B'))
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}