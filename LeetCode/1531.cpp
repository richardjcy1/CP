#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 105;
int dp[maxn][maxn][27][maxn];

/*

dp[idx][k][ch][cnt]:start from idx, can remove at most k, previous last characters are cnt ch -> min length
state transition: remove/not remove
not remove: same ch/not same ch

T:O(kn^2*26)
S:O(kn^2*26)
*/

class Solution {
public:
    string s;
    int k;
    int n;
    
    int solve(int idx, int k, int ch, int cnt)
    {
        if (idx == n)
        {
            return cnt <= 1 ? cnt : 1 + to_string(cnt).size();
        }
        if (dp[idx][k][ch][cnt] != -1) return dp[idx][k][ch][cnt];
        int cur = s[idx] - 'a';
        int ans = INF;
        if (cur == ch)
        {
            ans = min(ans, solve(idx + 1, k, ch, cnt + 1));
            if (k) ans = min(ans, solve(idx + 1, k - 1, ch, cnt));
        }
        else
        {
            int prev = ch == 26 ? 0 : (cnt == 1 ? 1 : 1 + to_string(cnt).size());
            ans = min(ans, prev + solve(idx + 1, k, cur, 1));
            if (k) ans = min(ans, solve(idx + 1, k - 1, ch, cnt));
        }
        return dp[idx][k][ch][cnt] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        this->s = s;
        this->k = k;
        n = s.size();
        return solve(0, k, 26, 0);
    }
};

/*

dp[left][k]: start from left, can remove at most k -> min length
build a group start from left: calculate frequency of each char and pick the most one to form a group

T:O(kn^2)
S:O(kn)
*/

class Solution2
{
    const static int N = 127;
    int dp[N][N];
    string str;
    int n;
    
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    
    int solve(int left, int k)
    {
        if (k < 0) return N;
        if (left >= n or n - left <= k) return 0;
        int& res = dp[left][k];
        if (res != -1) return res;
        res = N;
        
        int cnt[26] = {0};
        for (int j = left, most = 0; j < n; j++)
        {
            most = max(most, ++cnt[str[j] - 'a']);
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp, -1, sizeof dp);
        str = s;
        n = s.size();
        return solve(0, k);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution2 sol2;
    vector<string> strs{"aaabcccd","aabbaa","aaaaaaaaaaa"};
    vector<int> v{2,2,0};
    for (int i = 0; i < strs.size(); i++)
    {
        cout << sol2.getLengthOfOptimalCompression(strs[i], v[i]) << endl;
    }
    return 0;
}