#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

void binomialCoeff(vector<vector<int>>& c, int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int RencontresNumber(vector<vector<int>>& c, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j <= i)
            {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 1 && j == 0) dp[i][j] = 0;
                else if (j == 0) dp[i][j] = (i - 1) * (dp[i - 1][0] + dp[i - 2][0]);
                else dp[i][j] = c[i][j] * dp[i - j][0];
            }
        }
    }
    return dp[n][m];
}

int main() 
{ 
    int n = 7, m = 2; 
  
    vector<vector<int>> C(n + 1, vector<int>(m + 1));
    binomialCoeff(C, n, m); 
  
    cout << RencontresNumber(C, n, m) << endl; 
    return 0; 
}