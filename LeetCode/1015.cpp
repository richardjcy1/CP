#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


/*
Smallest integer divisible by k: (Math)

observation: length 1~10^5
modulo operation

only keep remainder modulo k

*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> vis;
        int cnt = 1;
        ll n = 1;
        while (n % k)
        {
            if (vis.find(n % k) != vis.end()) return -1;
            vis.insert(n % k);
            n = n * 10 + 1;
            n %= k;
            ++cnt;
        }
        return cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v{1,2,3,100000};
    Solution sol;
    for (int i: v) cout << sol.smallestRepunitDivByK(i) << endl;
    return 0;
}