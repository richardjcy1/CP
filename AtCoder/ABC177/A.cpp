#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d, t, s;
    cin >> d >> t >> s;
    int time = d % s == 0 ? d / s : d / s + 1;
    if (time <= t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}