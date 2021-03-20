#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
public:
/*
Greedy:

key observation: if III/DDD, the later element should be at least larger by 1 than previous element.

III sequence: start from min,min+1,min+2...only last element max
DDD sequence: start from max,max-1,max-2,...only last element min

why it works: make sure all I's can occupy enough space, and last element can start a decreasing sequence.

use set to easily keep order

O(nlogn)



*/
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans;
        vector<pair<int, char>> v;
        int start = 0, end = 0;
        while (end < n)
        {
            if (end + 1 < n && s[end] == s[end + 1])
            {
                ++end;
                continue;
            }
            v.push_back(make_pair(end - start + 1, s[start]));
            ++end;
            start = end;
        }
        if (start != end)
        {
            v.push_back(make_pair(end - start, s[start]));
        }
        set<int> st;
        for (int i = 0; i <= n; i++) st.insert(i);
        int m = v.size();
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                if (v[i].second == 'I')
                {
                    ans.push_back(0);
                    st.erase(0);
                }
                else
                {
                    ans.push_back(n);
                    st.erase(n);
                }
            }
            for (int j = 0; j < v[i].first; j++)
            {
                if (v[i].second == 'I')
                {
                    if (j == v[i].first - 1)
                    {
                        ans.push_back(*(st.rbegin()));
                        st.erase(*(st.rbegin()));
                    }
                    else
                    {
                        ans.push_back(*(st.begin()));
                        st.erase(*st.begin());
                    }
                }
                else
                {
                    if (j == v[i].first - 1)
                    {
                        ans.push_back(*(st.begin()));
                        st.erase(*st.begin());
                    }
                    else
                    {
                        ans.push_back(*(st.rbegin()));
                        st.erase(*st.rbegin());
                    }
                }
            }
        }
        return ans;
    }
};

class Solution2
{
public:
/*

Greedy:
If we encounter 'I', in order to make sure all next loops will satisfy, we put 1

If we encounter 'D', in order to make sure all next loops will satisfy, we put N

so we just keep minimum and maximum element (two pointers)

O(n)


*/
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        int lo = 0, hi = n;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I') ans.push_back(lo++);
            else ans.push_back(hi--);
        }
        ans.push_back(lo);
        return ans; 
    }
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> a = {"IDID", "III", "DDI"};
    Solution2 solution2;
    for (auto s: a)
    {
        for (int i: solution2.diStringMatch(s))
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}