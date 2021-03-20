#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a, b);
    cout << a * b / g << endl;
    return 0;
}