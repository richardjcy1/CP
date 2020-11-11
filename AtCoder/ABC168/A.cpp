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
    int last = n % 10;
    if (last == 2 || last == 4 || last == 5 || last == 7 || last == 9) cout << "hon" << endl;
    else if (last == 3) cout << "bon" << endl;
    else cout << "pon" << endl;
    return 0;
}