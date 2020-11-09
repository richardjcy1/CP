/*
*	author:		richardjcy
*	created:	2020/09/26/07:51.07
*/

#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    s[k - 1] = (char)(s[k - 1] - 'A' + 'a');
    cout << s << endl;
    return 0;
}