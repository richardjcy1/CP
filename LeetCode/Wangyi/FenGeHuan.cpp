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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = accumulate(a.begin(), a.end(), (ll)0);
        if (sum & 1) cout << "NO" << endl;
        else
        {
            ll target = sum / 2;
            unordered_set<ll> st;
            ll tot = 0;
            bool ok = false;
            for (int i = 0; i < n; i++)
            {
                tot += a[i];
                if (st.find(tot - target) != st.end())
                {
                    ok = true;
                    break;
                }
                st.insert(tot);
            }
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}