#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*

Number of paths with max score: (DP)

标准棋盘DP (pull DP)
用dp1,dp2维护最大值和最大值时的总数
dp1[i][j]=max(dp1[i+1][j],dp1[i][j+1],dp1[i+1][j+1])
dp2[i][j]为dp1[i][j]取到最大值时dp2[i+1][j],dp2[i][j+1],dp2[i+1][j+1]的和

base case:
dp1[m-1][n-1]=0,dp2[m-1][n-1]=1
最后一行和最后一列单独处理

return dp1[0][0],dp2[0][0]
注意board[0][0]='E'不能算在最大值里面

T:O(m*n)
S:O(m*n)
*/

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        board[0][0] = '0';
        vector<vector<ll>> dp1(m, vector<ll>(n));
        vector<vector<ll>> dp2(m, vector<ll>(n));
        dp1[m - 1][n - 1] = 0;
        dp2[m - 1][n - 1] = 1;
        for (int j = n - 2; ~j; j--)
        {
            if (board[m - 1][j] == 'X') continue;
            if (j == n - 2 || dp1[m - 1][j + 1])
            {
                dp1[m - 1][j] = (board[m - 1][j] - '0') + dp1[m - 1][j + 1];
                dp2[m - 1][j] = 1;
            }
        }
        for (int i = m - 2; ~i; i--)
        {
            if (board[i][n - 1] == 'X') continue;
            if (i == m - 2 || dp1[i + 1][n - 1])
            {
                dp1[i][n - 1] = (board[i][n - 1] - '0') + dp1[i + 1][n - 1];
                dp2[i][n - 1] = 1;
            }
        }
        for (int i = m - 2; ~i; i--)
        {
            for (int j = n - 2; ~j; j--)
            {
                if (board[i][j] == 'X') continue;
                if (dp1[i][j + 1])
                {
                    dp1[i][j] = max(dp1[i][j], board[i][j] - '0' + dp1[i][j + 1]);
                }
                if (dp1[i + 1][j])
                {
                    dp1[i][j] = max(dp1[i][j], board[i][j] - '0' + dp1[i + 1][j]);
                }
                if ((i == m - 2 && j == n - 2) || dp1[i + 1][j + 1])
                {
                    dp1[i][j] = max(dp1[i][j], board[i][j] - '0' + dp1[i + 1][j + 1]);
                }
                if (dp1[i][j] == board[i][j] - '0' + dp1[i][j + 1])
                {
                    dp2[i][j] += dp2[i][j + 1];
                    dp2[i][j] %= mod;
                }
                if (dp1[i][j] == board[i][j] - '0' + dp1[i + 1][j])
                {
                    dp2[i][j] += dp2[i + 1][j];
                    dp2[i][j] %= mod;
                }
                if (dp1[i][j] == board[i][j] - '0' + dp1[i + 1][j + 1])
                {
                    dp2[i][j] += dp2[i + 1][j + 1];
                    dp2[i][j] %= mod;
                }
                dp1[i][j] %= mod;
            }
        }
        return vector<int>{(int)(dp1[0][0] % mod), (int)(dp2[0][0] % mod)};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> board = {"E23","2X2","12S"};
    Solution sol;
    vector<int> ans = sol.pathsWithMaxScore(board); 
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}