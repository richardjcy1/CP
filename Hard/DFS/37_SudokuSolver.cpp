// Use backtracking/dfs to traverse all possible values at a[i][j]='.'
// the return value is true if going to the next cell; otherwise it is false
class Solution {
public:
    vector<vector<char>> a;
    int m, n;
    vector<vector<int>> row, col, block;
    
    bool solve(int idx)
    {
        if (idx == m * n) return true;
        int x = idx / n, y = idx % n;
        if (a[x][y] == '.')
        {
            for (int i = 1; i <= 9; i++)
            {
                if (!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i])
                {
                    row[x][i] = col[y][i] = block[x / 3 * 3 + y / 3][i] = 1;
                    a[x][y] = (char)(i + '0');
                    if (solve(idx + 1)) return true;
                    row[x][i] = col[y][i] = block[x / 3 * 3 + y / 3][i] = 0;
                    a[x][y] = '.';
                }
            }
        }
        else return solve(idx + 1);
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        a = b;
        m = a.size(), n = a[0].size();
        row = vector<vector<int>>(m, vector<int>(10));
        col = vector<vector<int>>(n, vector<int>(10));
        block = vector<vector<int>>(m * n / 9, vector<int>(10));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != '.')
                {
                    int v = a[i][j] - '0';
                    row[i][v] = col[j][v] = block[i / 3 * 3 + j / 3][v] = 1;
                }
            }
        }
        solve(0);
        b = a;
    }
};