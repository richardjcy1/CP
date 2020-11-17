#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Mirror Reflection (math, geometry)

key observation:
reflection can be expanded as straight line;
extend one square to multiple squares in the 2-D plane;
then find pattern in the number of receptor in terms of odd/even;

at some point, light hits one receptor, we have
n * p = m * q where m, n are all integers
worst case: n = q, m = p
so we just enumerate all possible 1 <= n <= q to find a smaller value

case 1: n odd m odd -> 1
case 2: n odd m even -> 0
case 3: n even m odd -> 2
case 4: n even m even -> invalid case, both can be divided by 2 to be case 1

T:O(q)
S:O(1)
*/

/*

Optimized Solution:
light starts from (0,0) then hits the first wall at (p,q), then (2*p,2*q) and so on
find the smallest k s.t p | kq
k = p / gcd(p, q)

T:O(logp)
S:O(1)
*/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int i = 1, j;
        for (; i <= q; i++)
        {
            if (i * p % q == 0)
            {
                j = i * p / q;
                break;
            }
        }
        if ((i & 1) && (j & 1)) return 1;
        if (!(i & 1) && (j & 1)) return 0;
        return 2;
    }
};

class Solution2
{
public:
    int mirrorReflection(int p, int q)
    {
        int g = __gcd(p, q);
        p /= g; p %= 2;
        q /= g; q %= 2;
        if (p && q) return 1;
        return p ? 0 : 2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution2 sol2;
    vector<int> P{2,3};
    vector<int> Q{1,1};
    for (int i = 0; i < P.size(); i++)
    {
        cout << sol2.mirrorReflection(P[i], Q[i]) << endl;
    }
    return 0;
}