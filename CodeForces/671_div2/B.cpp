/*
*	author:		richardjcy
*	created:	2020/09/19/12:13.36
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ull> v{1};
    for (int i = 1; i <= 31; i++)
    {
        ull e = pow(2, i);
        v.push_back(2 * v[i - 1] + (ull)e * e);
    }
    while (t--)
    {
        ull x;
        cin >> x;
        int cnt = 0, i = 0;
        while (1)
        {
            if (x >= v[i] && i < v.size())
            {
                x -= v[i++];
                ++cnt;
            }
            else break;
        }
        cout << cnt << endl;
    }

    return 0;
}