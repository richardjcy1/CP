const int INF = 0x3f3f3f3f;
const int maxn = 305;
int dp[maxn][30][30];

class Solution {
public:
    string s;
    int n;
    
    int dist(int a, int b)
    {
        int ra = a / 6, ca = a % 6;
        int rb = b / 6, cb = b % 6;
        return abs(ra - rb) + abs(ca - cb);
    }
    
    int solve(int idx, int x, int y)
    {
        if (idx == n) return 0;
        if (dp[idx][x][y] != -1) return dp[idx][x][y];
        int ans = min(solve(idx + 1, s[idx] - 'A', y) + dist(x, s[idx] - 'A'), solve(idx + 1, x, s[idx] - 'A') + dist(y, s[idx] - 'A'));
        return dp[idx][x][y] = ans;
    }
    
    int minimumDistance(string word) {
        /*dp[i][j][k]:start from ith char, one finger at letter j, another at k, min dist
        return dp[0][j][k]
        base:dp[n][j][k]=0
        dp[i][j][k]=min(dp[i+1][newj][k]+d1,dp[i+1][j][newk]+d2)
        */
        memset(dp, -1, sizeof dp);
        s = word;
        n = s.size();
        int ans = INF;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                ans = min(ans, solve(0, i, j));
            }
        }
        return ans;
    }
};