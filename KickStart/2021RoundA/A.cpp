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
    int kase = 0;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i]) cnt++;
        }
        cout << "Case #" << ++kase << ": " << abs(k - cnt) << endl;
    }
    return 0;
}