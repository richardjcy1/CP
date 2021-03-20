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
        int n, p;
        cin >> n >> p;
        vector<string> v;
        for (int i = 0; i < p; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        unordered_set<string> st;
        ll ans = pow(2, n);
        for (int i = 0; i < p; i++)
        {
            bool ok = true;
            for (auto s: st)
            {
                if (v[i].substr(0, s.size()) == s)
                {
                    ok = false;
                    break;
                }
            }
            if (ok) st.insert(v[i]);
        } 
        for (auto s: st)
        {
            ans -= pow(2, n - (int)s.size());
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}