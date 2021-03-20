#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x;
    cin >> x;
    ll y = 0, base = 100;
    while (base < x)
    {
        base += base / 100;
        ++y;
    }
    cout << y << endl;
    return 0;
}