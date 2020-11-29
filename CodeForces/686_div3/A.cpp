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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) a[i] = n - i + 1;
        if (n & 1) swap(a[1], a[n / 2 + 1]);
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}