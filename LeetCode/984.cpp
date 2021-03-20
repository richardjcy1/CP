#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
/*
Write the most common letter unless the letter has already been written twice.
*/
public:
    string strWithout3a3b(int A, int B) {
        string ans;
        while (A || B)
        {
            if (A >= B)
            {
                int n = ans.size();
                if (n >= 2 && ans[n - 1] == 'a' && ans[n - 2] == 'a')
                {
                    ans += 'b';
                    B--;
                }
                else
                {
                    ans += 'a';
                    A--;
                }
            }
            else
            {
                int n = ans.size();
                if (n >= 2 && ans[n - 1] == 'b' && ans[n - 2] == 'b')
                {
                    ans += 'a';
                    A--;
                }
                else
                {
                    ans += 'b';
                    B--;
                }
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    string strWithout3a3b(int A, int B) {
        if(A == 0) return string(B, 'b');
        else if(B == 0) return string(A, 'a');
        else if(A == B) return "ab" + strWithout3a3b(A - 1, B - 1);
        else if(A > B) return "aab" + strWithout3a3b(A - 2, B - 1);
        else return strWithout3a3b(A - 1, B - 2) + "abb";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution2 sol2;
    vector<int> A{1,4};
    vector<int> B{2,1};
    for (int i = 0; i < A.size(); i++)
    {
        cout << sol2.strWithout3a3b(A[i], B[i]) << endl;
    }
    return 0;
}