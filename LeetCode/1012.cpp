#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Numbers with repeated digits (Digit DP)

key observation: count of satisfied numbers in a given range

dfs(pos, state, limit): count of non-repeated-digit numbers from pos with previous state
and whether it is at limit

T:O(2^n*n) n is number of digits
S:O(2^n*n) n is number of digits
*/

int a[10];
int dp[10][1 << 10];

class Solution {
public:
    int dfs(int pos, int state, bool limit)
    {
        if (pos == -1) return 1;
        if (!limit && dp[pos][state] != -1) return dp[pos][state];
        int tmp = 0;
        int up = limit ? a[pos] : 9;
        for (int i = 0; i <= up; i++)
        {
            if (state != 1 && (state & 1 << i)) continue; // if not leading zeroes and repeated, skip this case
            if (state == 1) state = 0; // if leading zeroes, then 0 should not be counted as repeated digit
            tmp += dfs(pos - 1, 1 << i | state, limit && i == a[pos]);
        }
        if (!limit) dp[pos][state] = tmp; // if not in the limit case, we can reuse the result by memoization
        return tmp;
    }
    
    int solve(int x)
    {
        int pos = 0; // represent given number as digit array from least significant digit to most significant digit
        while (x)
        {
            a[pos++] = x % 10;
            x /= 10;
        }
        return dfs(pos - 1, 0, true);
    }
    
    int numDupDigitsAtMostN(int N) {
        memset(dp, -1, sizeof dp);
        return N - solve(N) + 1; // repeated-digit numbers = N - non-repeated-digit numbers + 1 (exclude 0 case)
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;
    vector<int> v{20,100,1000,(int)1e9};
    for (int i: v) cout << sol.numDupDigitsAtMostN(i) << endl;
    return 0;
}