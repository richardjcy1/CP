vector<vector<ll>> C;

void comb()
{
    C[1][0] = C[1][1] = 1;
    for (ll i = 2; i < 50; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (ll j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}