#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 5e4 + 5;
int dp[20][maxn];

/*

we have 1st parent for node.
use this, we can know 2nd parent, by searching [1st parent]'s [2^0 = 1st parent],
to know the 3rd parent, trace [2nd parent]'s [1st parent]
to know the 4th parent, trace [2nd parent]'s [2nd parent] -> we memory it as [2^2 = 4th parent]
to know the 5th parent, trace [4th parent]'s [1st parent]

*/

class TreeAncestor {
public:
    
    TreeAncestor(int n, vector<int>& parent) {
        memset(dp, -1, sizeof dp);
        int m = parent.size();
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = parent[i];
        }
        for (int i = 1; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int node = dp[i - 1][j];
                if (node != -1)
                {
                    dp[i][j] = dp[i - 1][node];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++)
        {
            if (k & (1 << i))
            {
                node = dp[i][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}