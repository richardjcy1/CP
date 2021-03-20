#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

void compute_prefix(string pattern, vector<int>& next)
{
    int i, j = -1;
    int m = pattern.size();
    next[0] = j;
    for (i = 1; i < m; i++)
    {
        while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[i] == pattern[j + 1]) j++;
        next[i] = j;
    }
}

void kmp(string text, string pattern)
{
    int i, j = -1;
    int n = text.size(), m = pattern.size();
    vector<int> next(m);
    compute_prefix(pattern, next);
    for (i = 0; i < n; i++)
    {
        while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
        if (text[i] == pattern[j + 1]) j++;
        if (j == m - 1)
        {
            cout << "found pattern at " << i - j << endl;
            j = next[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string text = "ABC ABCDAB ABCDABCDABDE";
    string pattern = "ABCDAB";
    kmp(text, pattern);
    return 0;
}