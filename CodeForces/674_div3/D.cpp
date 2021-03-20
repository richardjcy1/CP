#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int a[maxn];
int n;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    unordered_set<ll> st;
    st.insert(0);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (st.find(sum) != st.end())
        {
            ++ans;
            st.clear();
            st.insert(0);
            st.insert(a[i]);
            sum = a[i];
        }
        else
        {
            st.insert(sum);
        }
    }
    cout << ans << endl;
    return 0;
}