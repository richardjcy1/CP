#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++)
    {
        x += (a[i] - '0');
        y += (b[i] - '0');
    }
    if (x >= y) cout << x << endl;
    else cout << y << endl;
    return 0;
}