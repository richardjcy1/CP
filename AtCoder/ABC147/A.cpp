#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
    return 0;
}