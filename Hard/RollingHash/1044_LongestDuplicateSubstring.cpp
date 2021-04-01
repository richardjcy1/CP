#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const ll MOD = pow(2, 32);
int a = 26;
int n;

int search(const string_view& s, int L, vector<int>& nums)
{
    ll h = 0, aL = 1;
    for (int i = 0; i < L; i++) h = (h * a + nums[i]) % MOD;
    for (int i = 1; i <= L; i++) aL = (aL * a) % MOD;
    unordered_map<ll, vector<ll>> seen;
    seen[h].push_back(0);
    for (int start = 1; start < n - L + 1; start++)
    {
        h = h * a;
        h = (h - nums[start - 1] * aL % MOD + MOD) % MOD;
        h = (h + nums[start + L - 1]) % MOD;
        if (seen.find(h) != seen.end())
        {
            for (int i: seen[h])
            {
                if (s.substr(i, L) == s.substr(start, L)) return i;
            }
        }
        else seen[h].push_back(start);
    }
    return -1;
}

class Solution {
public:
    string longestDupSubstring(string S) {
        n = S.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = S[i] - 'a';
        int low = 1, high = n - 1;
        string_view s{S};
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int startIndex = search(s, mid, nums);
            if (startIndex == -1) high = mid - 1;
            else low = mid + 1;
        }
        int startIndex = search(s, high, nums);
        return startIndex == -1 ? "" : S.substr(startIndex, high);
    }
};