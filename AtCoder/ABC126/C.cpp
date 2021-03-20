/*
*	author:		richardjcy
*	created:	2020/09/26/08:07.13
*/

#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    long double ans = 0.0;
    for (int i = 1; i <= min(n, k - 1); i++)
    {
        int idx = ceil(log2(k / (i + 0.0)));
        long double tmp = pow(0.5, idx);
        tmp /= (n + 0.0);
        ans += tmp;
    }
    ans += max(0.0, (n - k + 1) / (n + 0.0));
    cout << setprecision(15) << ans << endl;
    return 0;
}