#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

struct Block
{
    int x, y, h, w;
    Block(int xx, int yy, int hh, int ww): x(xx), y(yy), h(hh), w(ww) {}
    bool overlap(const Block& other)
    {
        if (other.x + h <= x || other.x >= x + h) return true;
        if (other.y + w <= y || y + w <= other.y) return true;
        return false;
    }
};

vector<Block> v;
int n;
unordered_map<string, bool> dp;

bool check()
{
    if (v[1].x == 3 && v[0].y == 1) return true;
    return false;
}

bool solve(string state)
{
    if (check(state)) return true;
    if (dp.find(state) != dp.end()) return dp[state];
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        int idx = state[3 * i] - '0';
        int x = state[3 * i + 1] - '0';
        int y = state[3 * i + 2] - '0';
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dirx[j];
            int ny = y + diry[j];
            if (nx >= 0 && nx + v[i].h <= 5 && ny >= 0 && ny + v[i].w <= 4)
            {
                string tmp = state;
                tmp[3 * i + 1] = (char)('0' + nx);
                tmp[3 * i + 2] = (char)('0' + ny);
                bool ok = true;
                v[i].x = nx;
                v[i].y = ny;
                for (int k = 0; k < n; k++)
                {
                    if (i != k && v[i].overlap(v[k]))
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    ans = ans || solve(tmp);
                }
                v[i].x = x;
                v[i].y = y;
            }
        }
    }
    return dp[state] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp = {};
    v = {};
    v.push_back(Block(0, 0, 2, 1));
    v.push_back(Block(0, 1, 2, 2));
    v.push_back(Block(0, 3, 2, 1));
    v.push_back(Block(2, 0, 2, 1));
    v.push_back(Block(2, 1, 1, 2));
    v.push_back(Block(2, 3, 2, 1));
    v.push_back(Block(3, 1, 1, 1));
    v.push_back(Block(3, 2, 1, 1));
    v.push_back(Block(4, 0, 1, 1));
    v.push_back(Block(4, 3, 1, 1));
    string state;
    for (int i = 0; i < 10; i++)
    {
        state += to_string(i) + to_string(v[i].x) + to_string(v[i].y);
    }
    cout << boolalpha << solve(state) << endl;
    return 0;
}