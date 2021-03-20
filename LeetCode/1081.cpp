#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
    /*
    
    Monotonous stack + greedy:
    
    keep increasing stack + keep visited char

    */
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> vis(26);
        string ans;
        string ret;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            while (!ans.empty() && !vis[s[i] - 'a'] && ans.back() > s[i] && cnt[ans.back() - 'a'])
            {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            if (!vis[s[i] - 'a']) 
            {
                vis[s[i] - 'a'] = true;
                ans += s[i];
            }
            // if (ret.empty()) ret = ans;
            // else if (ans < ret) ret = ans;
            cnt[s[i] - 'a']--;
            // cout << ans << endl;
        }
        return ans;
    }
};

class Solution2
{
public:
/*

monotonous stack

just keep last index of each char + visited array


*/
    string smallestSubsequence(string s)
    {
        string ans;
        vector<int> last(26), seen(26);
        int n = s.size();
        for (int i = 0; i < n; i++) last[s[i] - 'a'] = i;
        for (int i = 0; i < n; i++)
        {
            if (seen[s[i] - 'a']++) continue;
            while (!ans.empty() && ans.back() > s[i] && i < last[ans.back() - 'a'])
            {
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans += s[i];
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> a = {"bcabc", "cbacdcbc"};
    Solution2 sol2;
    for (auto s: a)
    {
        cout << sol2.smallestSubsequence(s) << endl;
    }

    return 0;
}