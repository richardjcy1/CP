#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(10);
    for (int i = 0; i < k; i++) 
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int i = n;
    for (; ; i++)
    {
        string s = to_string(i);
        bool ok = true;
        for (char c: s)
        {
            if (a[c - '0'])
            {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    cout << i << endl;
    return 0;
}