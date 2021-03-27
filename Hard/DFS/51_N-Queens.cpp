class Solution {
public:
    vector<vector<string>> ans;
    int n;
    vector<string> a;
    
    bool check(int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            if (a[i][y] == 'Q') return false;
        }
        for (int j = 0; j < y; j++)
        {
            if (a[x][j] == 'Q') return false;
        }
        for (int i = x, j = y; ~i && ~j; i--, j--)
        {
            if (a[i][j] == 'Q') return false;
        }
        for (int i = x, j = y; ~i && j < n; i--, j++)
        {
            if (a[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void solve(int i)
    {
        if (i == n)
        {
            ans.push_back(a);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '.' && check(i, j))
            {
                a[i][j] = 'Q';
                solve(i + 1);
                a[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        ans = {};
        this->n = n;
        a = vector<string>(n, string(n, '.'));
        solve(0);
        return ans;
    }
};