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
        int ans = 0;
        int start = 1, end = 1;
        int d = 1, cnt = 0;
        while (end < n)
        {
            if (end + 1 < n && a[end] < a[end + 1])
            {
                ++end;
                continue;
            }
            --d;
            cnt += end - start + 1;
            if (d == 0)
            {
                ++ans;
                d = cnt;
                ++end;
                start = end;
                cnt = 0;
            }
            else 
            {
                ++end;
                start = end;
            }

        }
        if (cnt) ++ans;
        cout << ans << endl;
    }
    return 0;
}