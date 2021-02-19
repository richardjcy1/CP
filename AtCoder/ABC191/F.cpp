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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    unordered_set<int> st{a[0]};
    for (int i = 1; i < n; i++) st.insert(__gcd(a[0], a[i]));
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = __gcd(a[i], a[j]);
            if (tmp <= a[0]) st.insert(tmp);
        }
    }
    cout << (int)st.size() << endl;
    return 0;
}