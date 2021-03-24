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
        int a, b;
        cin >> a >> b;
        int diff = b - a;
        if (diff % 10 == 0) cout << abs(diff) / 10 << endl;
        else cout << abs(diff) / 10 + 1 << endl;
    }
    return 0;
}