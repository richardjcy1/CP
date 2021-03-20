#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
/*
Greedy:
check a[0]...a[n-1] one by one:
if a[0] == 1, ok; else we need to flip a[0]...a[k-1];
then check a[1] in the same way;
in order to maintain all flips from a[0]...a[k-1], use a map mp
mp[0]=1,mp[k]=-1. like meeting room, also use cnt to accumulate the result

for the last k elements, we need to check if previous flips can work or not.

Also for a position, at most 1 flip is needed because flipping twice remains the same.

*/
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> mp;
        int cnt = 0, ans = 0;
        for (int i = 0; i <= n - k; i++)
        {
            cnt += mp[i];
            if ((cnt + a[i]) % 2 == 0)
            {
                ++ans;
                mp[i] = 1;
                mp[i + k] = -1;
                cnt++;
            }
        }
        for (int i = n - k + 1; i < n; i++)
        {
            cnt += mp[i];
            if ((cnt + a[i]) % 2 == 0) return -1;
        }
        return ans;
    }
};

class Solution2
{
public:
   int minKBitFlips(vector<int>& a, int k) 
   {
       int n = a.size();
       vector<int> hint(n);
       int ans = 0, flip = 0;
       for (int i = 0; i < n; i++)
       {
           flip ^= hint[i];
           if (a[i] == flip)
           {
               ans++;
               if (i + k > n) return -1;
               flip ^= 1;
               if (i + k < n) hint[i + k] ^= 1;
           }
       }
       return ans;
   }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Solution2 sol2;
    vector<vector<int>> A{{0,1,0},{1,1,0},{0,0,0,1,0,1,1,0}};
    vector<int> K{1,2,3};
    for (int i = 0; i < A.size(); i++)
    {
        cout << sol2.minKBitFlips(A[i], K[i]) << endl;
    }
    return 0;
}