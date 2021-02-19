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
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n;)
        {
            if (a[i] == 1)
            {
                ++ans;
                i++;
                continue;
            }
            int j = i + a[i] - 1;
            while (j < n && a[j] != j - i + 1)
            {
                j++;
            }
            if (j < n)
            {
                ++ans;
                i = j + 1;
            }
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}