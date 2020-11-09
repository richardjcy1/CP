#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int ans = 0;
        int i = 0, j = n - 1;
        int tot = 0;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            tot += (s[i] - '0');
        }
        ans = max(ans, tot);
        for (int i = (n + 1) / 2; i < n; i++)
        {
            tot += (s[i] - '0') - (s[i - (n + 1) / 2] - '0');
            ans = max(ans, tot);
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}