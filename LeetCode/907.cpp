#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
/*
min property: span left and right, find the first smaller number
monotonous increasing stack

pay attention to equal: only count once

[L] a[i] [R]
total number of subarrays with a[i] as minimum
L * R + L + R + 1

*/
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        stk.push(n - 1);
        for (int i = n - 2; ~i; i--)
        {
            while (!stk.empty() && a[stk.top()] > a[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        stack<int> stk2;
        stk2.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!stk2.empty() && a[stk2.top()] >= a[i]) stk2.pop();
            if (!stk2.empty()) left[i] = stk2.top();
            stk2.push(i);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << "i: " << i << " " << left[i] << " " << right[i] << endl;
            ll l = i - left[i] - 1;
            ll r = right[i] - i - 1;
            ans += (l * r + l + r + 1) * a[i];
            ans %= mod;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v{3,1,2,4};
    Solution sol;
    cout << sol.sumSubarrayMins(v) << endl;


    return 0;
}