#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*

each position can be 0 (blocked), 1 (nobody), 2 (somebody)
dp[cur][mask]= max(
seats[cur] == '#': dp[cur-1][prev_mask] prev_mask = mask / 3 + pow(3, n + 1) * seats[cur - n - 1]
seats[cur] == '.': dp[cur-1][prev_mask], 1 + dp[cur-1][prev_mask'])
prev_mask = (mask - seats[cur]) / 3 + pow(3, n + 1) * seats[cur - n - 1]

return max(dp[m*n][mask])
base: dp[0][0] = 1;

0 1 2 3 4 5
6 7 8 9 10 11
12 13 14 15 16 17

T:O(m*n*3^n)

dp[cur + 1][mask] = max(dp[cur + 1][mask], dp[cur][mask])

# . .
. # .


*/

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(n, vector<int>(1 << (n + 1)));
        for (int i = 0; i < m * n; i++)
        {
            for (int mask = 0; mask < 1 << (n + 1); mask++)
            {
                int row = i / n, col = i % n;
                if (seats[row][col] == '#')
                {
                    dp[(col + 1) % n][(mask % (1 << n)) * 2] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2], dp[col][mask]);           
                }
                else
                {
                    dp[(col + 1) % n][(mask % (1 << n)) * 2] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2], dp[col][mask]);
                    if ((col == 0 || (mask % 2) != 1) && (col == n - 1 || (mask / (1 << (n - 2))) % 2 != 1) && (col == 0 || (mask / (int)(1 << n)) % 2 != 1))
                    {
                        dp[(col + 1) % n][(mask % (1 << n)) * 2 + 1] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2 + 1], 1 + dp[col][mask]);
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < 1 << (n + 1); mask++)
        {
            ans = max(ans, dp[0][mask]);
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}