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
    if (n % 1000 == 0) cout << 0 << endl;
    else cout << 1000 - n % 1000 << endl;
    return 0;
}