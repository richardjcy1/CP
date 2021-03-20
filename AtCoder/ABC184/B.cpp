#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int ans = x;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            ans++;
        }
        else if (s[i] == 'x')
        {
            if (ans > 0) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
