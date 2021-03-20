#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

bool check8(int x)
{
    while (x)
    {
        if (x % 8 == 7) return false;
        x /= 8;
    }
    return true;
}

bool check10(int x)
{
    while (x)
    {
        if (x % 10 == 7) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (check8(i) && check10(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}