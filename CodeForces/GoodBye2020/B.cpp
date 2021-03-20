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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ma = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] - 1 == ma)
            {
                ma = a[i];
            }
            else if (a[i] == ma)
            {
                ++a[i];
                ma = a[i];
            }
            else if (a[i] > ma + 1)
            {
                ma = a[i];
            }
        }
        unordered_set<int> st(a.begin(), a.end());
        cout << (int)st.size() << endl;
    }
    return 0;
}