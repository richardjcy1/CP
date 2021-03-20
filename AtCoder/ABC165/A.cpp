#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;
    bool ok = false;
    for (int i = a; i <= b; i++)
    {
        if (i % k == 0)
        {
            ok = true;
            break;
        }
    }
    if (ok) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}