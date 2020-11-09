#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ma = *max_element(a.begin(), a.end());
    int ans = 0;
    int tot = 0;
    for (int i = 2; i <= ma; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % i == 0)
            {
                cnt++;
            }
        }
        if (cnt > tot)
        {
            tot = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}