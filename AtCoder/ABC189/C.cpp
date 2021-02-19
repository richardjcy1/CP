#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int largestRectangleArea(vector<ll>& h) {
    int n = h.size();
    stack<ll> S;
    vector<ll> left(n, -1), right(n, n);
    S.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!S.empty() && h[S.top()] >= h[i]) S.pop();
        if (!S.empty()) left[i] = S.top();
        S.push(i);
    }
    S = {};
    S.push(n - 1);
    for (int i = n - 2; ~i; i--)
    {
        while (!S.empty() && h[S.top()] >= h[i]) S.pop();
        if (!S.empty()) right[i] = S.top();
        S.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, h[i] * (right[i] - left[i] - 1));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll > a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << largestRectangleArea(a) << endl; 
    return 0;
}