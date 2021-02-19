#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b, k;
    cin >> a >> b >> k;
    if (a >= k)
    {
        cout << a - k << " " << b << endl;
    }
    else if (a + b >= k)
    {
        cout << 0 << " " << a + b - k << endl;
    }
    else cout << 0 << " " << 0 << endl;
    return 0;
}