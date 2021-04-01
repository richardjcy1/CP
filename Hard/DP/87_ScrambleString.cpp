const int maxn = 35;
int dp[maxn][maxn][maxn][maxn];

class Solution {
public:
    string s, t;
    
    bool solve(int pos0, int pos1, int pos2, int pos3)
    {
        int m = pos1 - pos0 + 1, n = pos3 - pos2 + 1;
        if (m != n) return false;
        if (s.substr(pos0, m) == t.substr(pos2, m)) return true;
        if (m == 1) return false;
        if (dp[pos0][pos1][pos2][pos3] != -1) return dp[pos0][pos1][pos2][pos3];
        bool ok = false;
        for (int i = 0; i < m - 1; i++)
        {
            ok = ok || (solve(pos0 + 0, pos0 + i, pos2 + 0, pos2 + i) && solve(pos0 + i + 1, pos1, pos2 + i + 1, pos3));
            ok = ok || (solve(pos0 + 0, pos0 + i, pos3 - i, pos3) && solve(pos0 + i + 1, pos1, pos2 + 0, pos3 - i - 1));
            if (ok) break;
        }
        return dp[pos0][pos1][pos2][pos3] = ok;
    }
    
    bool isScramble(string s1, string s2) {
        s = s1;
        t = s2;
        memset(dp, -1, sizeof dp);
        return solve(0, s.size() - 1, 0, t.size() - 1);
    }
};