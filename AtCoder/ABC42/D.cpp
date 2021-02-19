#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

void comb()
{
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}