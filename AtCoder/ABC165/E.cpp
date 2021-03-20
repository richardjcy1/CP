#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int l1 = 1, r1 = m + 1, l2 = r1 + 1, r2 = l2 + m - 1;
    while (l1 < r1)
    {
        cout << l1 << " " << r1 << endl;
        l1++; r1--;
    }
    while (l2 < r2)
    {
        cout << l2 << " " << r2 << endl;
        ++l2; --r2;
    }
    return 0;
}