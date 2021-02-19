#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <unordered_map>
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
        if (other.x + other.h <= x || other.x >= x + h) return false;
        if (other.y + other.w <= y || y + w <= other.y) return false;
        return true;
    }
};

vector<Block> v;
int n;
int cnt = 0;
unordered_map<string, int> dp;

bool check(const string& state)
{
    if (state[2] == '3' && state[3] == '1') return true;
    return false;
}

int solve(string state)
{
    if (check(state)) return 1;
    if (dp.find(state) != dp.end() && dp[state] != 2) return dp[state];
    if (dp.find(state) != dp.end() && dp[state] == 2) return 0;
    int ans = 0;
    dp[state] = 2;
    cout << state << endl;
    // cout << ++cnt << endl;
    for (int i = 0; i < n; i++)
    {
        int x = state[2 * i + 1] - '0';
        int y = state[2 * i + 2] - '0';
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dirx[j];
            int ny = y + diry[j];
            if (nx >= 0 && nx + v[i].h <= 5 && ny >= 0 && ny + v[i].w <= 4)
            {
                string tmp = state;
                tmp[2 * i + 1] = (char)('0' + nx);
                tmp[2 * i + 2] = (char)('0' + ny);
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
    n = v.size();
    string state;
    for (int i = 0; i < 10; i++)
    {
        state += to_string(v[i].x) + to_string(v[i].y);
    }
    cout << solve(state) << endl;
    return 0;
}