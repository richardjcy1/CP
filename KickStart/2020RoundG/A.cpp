#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        set<int> st1, st2; 
        for (int i = 0; i < n; i++)
        {
            if (i + 4 <= n && s.substr(i, 4) == "KICK")
            {
                st1.insert(i);
            }
            if (i + 5 <= n && s.substr(i, 5) == "START")
            {
                st2.insert(i);
            }
        }
        ll ans = 0;
        int u = st1.size(), v = st2.size();
        for (auto x: st1)
        {
            auto it = st2.lower_bound(x);
            ans += (v - distance(st2.begin(), it));
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}