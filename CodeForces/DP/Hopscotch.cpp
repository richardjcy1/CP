#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int getIndex(int x, int y)
{
    return x * (x + 1) / 2 + y;
}

bool powerOfTwo(int x)
{
    if (x == 1) return true;
    if (x & 1) return false;
    return powerOfTwo(x / 2);
}

int dp[1 << 15];
struct State
{
    int x1, y1, x2, y2, x3, y3;
    State(int a, int b, int c, int d, int e, int f): x1(a), y1(b), x2(c), y2(d), x3(e), y3(f) {}
};

vector<State> v;

void helper(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //cout << "move (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") remove (" << x3 << "," << y3 << ")" << endl;
    v.push_back(State(x1, y1, x2, y2, x3, y3));
}

bool solve(int mask)
{
    if (powerOfTwo(mask)) return true;
    if (dp[mask] != -1) return dp[mask];
    bool ans = false;
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int idx = i * (i + 1) / 2 + j;
            if ((mask & (1 << idx)) && j - 2 >= 0 && (mask & (1 << (idx - 1))) && ((mask & (1 << (idx - 2))) == 0))
            {
                ans = ans || (solve((mask | (1 << (idx - 2))) - (1 << idx) - (1 << (idx - 1))));
                if (ans)
                {
                    helper(i, j, i, j - 2, i, j - 1);
                }
            }
            if (!ans && (mask & (1 << idx)) && j + 2 <= i && (mask & (1 << (idx + 1))) && ((mask & (1 << (idx + 2))) == 0))
            {
                ans = ans || (solve((mask + (1 << (idx + 2)) - (1 << idx) - (1 << (idx + 1)))));
                if (ans)
                {
                    helper(i, j, i, j + 2, i, j + 1);
                }
            }
            if (!ans && (mask & (1 << idx)) && i - 2 >= 0 && j <= i - 1 && j <= i - 2 && (mask & (1 << getIndex(i - 1, j))) && ((mask && (1 << getIndex(i - 2,j))) == 0))
            {
                ans = ans || solve((mask + (1 << getIndex(i - 2, j)) - (1 << getIndex(i - 1, j)) - (1 << getIndex(i, j))));
                if (ans)
                {
                    helper(i, j, i - 2, j, i - 1, j);
                }
            }
            if (!ans && (mask & (1 << getIndex(i, j))) && i + 2 <= 4 && (mask & (1 << getIndex(i + 1, j))) && ((mask & (1 << getIndex(i + 2, j))) == 0))
            {
                ans = ans || solve((mask + (1 << getIndex(i + 2, j)) - (1 << getIndex(i + 1, j)) - (1 << getIndex(i, j))));
                if (ans)
                {
                    helper(i, j, i + 2, j, i + 1, j);
                }
            }
            if (!ans && (mask & (1 << getIndex(i, j))) && i - 2 >= 0 && j - 2 >= 0 && (mask & (1 << getIndex(i - 1, j - 1))) && ((mask & (1 << getIndex(i - 2, j - 2))) == 0))
            {
                ans = ans || solve((mask + (1 << getIndex(i - 2, j - 2)) - (1 << getIndex(i - 1, j - 1)) - (1 << getIndex(i, j))));
                if (ans)
                {
                    helper(i, j, i - 2, j - 2, i - 1, j - 1);
                }
            }
            if (!ans && (mask & (1 << getIndex(i, j))) && i + 2 <= 4 && (mask & (1 << getIndex(i + 1, j + 1))) && ((mask & (1 << getIndex(i + 2, j + 2))) == 0))
            {
                ans = ans || solve((mask + (1 << getIndex(i + 2, j + 2)) - (1 << getIndex(i + 1, j + 1)) - (1 << getIndex(i, j))));
                if (ans)
                {
                    helper(i, j, i + 2, j + 2, i + 1, j + 1);
                }
            }
        }
    }
    return dp[mask] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    v = {};
    bool ans = false;
    int idx = -1;
    for (int i = 0; i < 15; i++)
    {
        ans = ans || solve((1 << 15) - 1 - (1 << i));
        if (ans && idx == -1) idx = i;
    }
    int m = v.size();
    cout << "start from position (" << idx << ")" << endl;
    for (int i = m - 1; ~i; i--)
    {

        cout << "move (" << v[i].x1 << "," << v[i].y1 << ") to (" << v[i].x2 << "," << v[i].y2 << ") remove (" << v[i].x3 << "," << v[i].y3 << ")" << endl;
    }

    return 0;
}